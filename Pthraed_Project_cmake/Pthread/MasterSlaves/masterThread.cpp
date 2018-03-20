/*=============================================================================
start of file
=============================================================================*/

//! \file    masterThread.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   masterThreadClass - Implemenation of main thread which lauches child thread which will be added dynamically
//!
//---------------------------------------------------------------------------  
#include<iostream>
#include <masterThread.hpp>
#include "threadWrapper.hpp"
#include "locker.hpp"

int count = 0;
namespace framework {

masterThreadClass::masterThreadClass() {
	mNumChildThreads = 0;
	nCompletedThreads = 0;
	mRunnableThreads.clear();
	mIsRunning = false;
	mFirstTime = true;
}

masterThreadClass::~masterThreadClass() {
	mRunnableThreads.clear();
}

void masterThreadClass::addThreadToRunList(void *obj) {
	childThreadClassType *tmpObj = static_cast<childThreadClassType*>(obj);
	std::string str = tmpObj->getIdentifier();
	mRunnableThreads.insert(pairType(str,tmpObj));
}
void masterThreadClass::launch(void* args) {
	childThreadClassType* tmpObj = static_cast<childThreadClassType*>(args);
	tmpObj->launch(tmpObj);
}
void masterThreadClass::notifyMasterThread() {
	std::cout << "Thread " << count << "is done" << std::endl;
	count++;
	mCond.publish();
}
void masterThreadClass::notifyThreadCompleteStatus() {
	threading::locker<threading::Mutex> obj(mrunningThreadsMutex);
	nCompletedThreads++;
}
bool masterThreadClass::updateThreadStatus() {
	threading::locker<threading::Mutex> obj(mMutex);
	if (nCompletedThreads == mNumChildThreads) {
		return false;
	}
	return true;
}

void masterThreadClass::waitForCompletion() {
	std::map<std::string, childThreadClassType*>::iterator it;
	while (mIsRunning) {
		mIsRunning = updateThreadStatus();
		if (mIsRunning) {
			for (it = mRunnableThreads.begin(); it != mRunnableThreads.end(); it++) {
				it->second->publish();
			}

			mMutex.lock();
			mCond.wait(&mMutex);
			mMutex.unlock();
		}
	}
	
}


void masterThreadClass::startAllThreads() {
	if (mFirstTime) {
		mIsRunning = true;
		launchThreads();
		mFirstTime = false;
	}
}
void* masterThreadClass::waitForCompletion(void* args) {
	masterThreadClass* tmpobj = static_cast<masterThreadClass*>(args);
	tmpobj->waitForCompletion();
	return 0;
}

void masterThreadClass::joinMasterThread() {
	mMasterThreadObj.joinThreads(&mMasterThreadObj);
}
void masterThreadClass::launchThreads() {
	std::map<std::string, childThreadClassType*>::iterator it;
	for (it = mRunnableThreads.begin(); it != mRunnableThreads.end(); it++) {
		launch(it->second);
		mNumChildThreads++;
	}
	
	mMasterThreadObj.initThreadParams(masterThreadClass::waitForCompletion, this);
	mMasterThreadObj.createThread();
}

}