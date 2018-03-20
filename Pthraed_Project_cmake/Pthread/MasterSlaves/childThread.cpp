/*=============================================================================
start of file
=============================================================================*/

//! \file    childThread.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   chilThreadClass - Implemenation of main thread for child thread which will be launched by master thread
//!
//---------------------------------------------------------------------------  
#include <cassert>
#include <iostream>
#include "commonHeader.hpp"
#include "childThread.hpp"
#include "masterThread.hpp"

namespace framework {

	childThreadClass::childThreadClass() {
		mFunc = runFunction;
		mIsRunning = false;
		mCamNum = 999;
	}

	childThreadClass::~childThreadClass() {

	}

	void childThreadClass::launch(void * args) {
		childThreadClass* threadInfo = static_cast<childThreadClass*> (args);
		mThread.initThreadParams(mFunc, args);
		mIsRunning = true;
		mThread.createThread();
	}

	void childThreadClass::publish() {
		mCond.publish();
	}

	void childThreadClass::subscribe(void *args) {
		mMasterObj = static_cast<masterClassType*>(args);
		mMasterObj->addThreadToRunList(this);
	}

	void childThreadClass::waitForMaster() {
		mCond.wait(&mMutex);
	}
	void* childThreadClass::runFunction(void* args) {
		childThreadClass* tmpObj = static_cast<childThreadClass*>(args);
		tmpObj->run(tmpObj);
		return 0;
	}
	bool childThreadClass::run() {
		//overridded by derived class
		return true;
	}
	void childThreadClass::run(void* args) {
		if (mIsRunning) {
			childThreadClass* tmpObj = static_cast<childThreadClass*>(args);
			mMutex.lock();
			mCond.wait(&mMutex);
			mMutex.unlock();
			if (this->run()) {
				mMasterObj->notifyThreadCompleteStatus();
				mMasterObj->notifyMasterThread();
				mIsRunning = false;
			}
		}
	}
}