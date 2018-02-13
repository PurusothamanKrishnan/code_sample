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

#include <masterThread.hpp>

namespace framework {

masterThreadClass::masterThreadClass() {
	mNumChildThreads = 0;
	mRunnableThreads.clear();
}

masterThreadClass::~masterThreadClass() {
	mRunnableThreads.clear();
}

void masterThreadClass::addThreadToRunList(void *obj) {
	childThreadClassType *tmpObj = static_cast<childThreadClassType*>(obj);
	std::string str = tmpObj->getThreadIdentifier();
	mRunnableThreads.insert(pairType(str,tmpObj));
}


}