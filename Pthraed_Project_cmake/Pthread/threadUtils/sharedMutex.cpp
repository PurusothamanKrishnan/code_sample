/*=============================================================================
start of file
=============================================================================*/

//! \file    conditionWrapper.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Pthread Condition class implementation 
//!
//---------------------------------------------------------------------------   
#include<iostream>
#include "sharedMutex.hpp"
using namespace std;

namespace threading {

Mutex sharedMutex::mSharedMutexObj;

void sharedMutex::wait(void* obj) {
	sharedMutex* tmpObj = static_cast <sharedMutex*>(obj);
	tmpObj->mCond.wait((void*)(&mSharedMutexObj));
}

void sharedMutex::mutexLock() {
	mSharedMutexObj.lock();
}

void sharedMutex::mutexUnLock() {
	mSharedMutexObj.unlock();
}
sharedMutex::sharedMutex() {

}

sharedMutex::~sharedMutex() {

}

void sharedMutex::wait() {
	wait(this);
}

void sharedMutex::publish(void* obj) {
	sharedMutex* tmpObj = static_cast<sharedMutex*>(obj);
	tmpObj->publish();
}

void sharedMutex::publish() {
	mCond.publish();
}

}