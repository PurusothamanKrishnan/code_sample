/*=============================================================================
start of file
=============================================================================*/

//! \file    threadWrapper.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   thread implementation
//!
//--------------------------------------------------------------------------- 
#include <iostream>
#include "threadWrapper.hpp"

using namespace std;

namespace threading {

	threadClass::threadClass() {
		cout << "Call Init Function" << endl;
		mThreadInfo = NULL;
	}

	threadClass::threadClass(void *(*func)(void*), void* args) {
		mThreadInfo = new threadInfo;
		initThreadParams(func, args);
	}

	threadClass::threadClass(void *(*func)(void*), void* args,pthread_attr_t* attrs) {
		mThreadInfo = new threadInfo;
		mThreadInfo->attr = attrs;
		initThreadParams(func, args);
	}

	threadClass::~threadClass() {
		if (mThreadInfo != NULL) {
			int ret;
			delete mThreadInfo->attr;
			delete mThreadInfo;
			mThreadInfo = NULL;
		}
	}

	void threadClass::initThreadParams(void *(*func)(void*), void* args) {
		if (mThreadInfo == NULL) {
			mThreadInfo = new threadParams;
		}
		mThreadInfo->tFunc = func;
		mThreadInfo->args = args;
		mThreadInfo->attr = new pthread_attr_t;
		pthread_attr_init(mThreadInfo->attr);
	}
	void threadClass::createThread() {
		if (mThreadInfo != NULL) {
			int ret = pthread_create(&mThreadInfo->tID, mThreadInfo->attr, mThreadInfo->tFunc, mThreadInfo->args);
			if (ret != 0) {
				cout << "Error in creating thread" << endl;
				exit(EXIT_FAILURE);
			}
		}
		else {
			cout << "Initialize Thread Params First" << endl;
		}
	}
	void threadClass::createThread( void* params) {
		if (mThreadInfo == NULL) {
			threadInfo* tInfo = static_cast<threadInfo*> (params);
			mThreadInfo = (threadInfo *) new char[sizeof(threadInfo)];
			initThreadParams(tInfo->tFunc, tInfo->args);
		}
		else {
			threadInfo* tInfo = static_cast<threadInfo*> (params);
			mThreadInfo->attr = tInfo->attr;
			initThreadParams(tInfo->tFunc, tInfo->args);
		}
		createThread();
	}

	void threadClass::joinThreads(void* args) {
		threadClass* tmpObj = static_cast<threadClass *>(args);
		pthread_join(tmpObj->getThreadID(), NULL);
	}

}