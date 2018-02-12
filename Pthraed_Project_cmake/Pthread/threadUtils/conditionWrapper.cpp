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
#include <iostream>
#include "conditionWrapper.hpp"
#include "mutex.hpp"

using namespace std;
namespace threading {

condClass::condClass() {
	pthread_condattr_t* attr = new pthread_condattr_t;
	mCond = new pthread_cond_t;
	if (pthread_condattr_init(attr)) {
		cout << "Error in intilizing condtion attribute" << endl;
		exit(EXIT_FAILURE);
	}
	if (pthread_cond_init(mCond, attr)) {
		cout << "Error in intilizing condtion" << endl;
		exit(EXIT_FAILURE);
	}
	if (pthread_condattr_destroy(attr)) {
		cout << "Error in intilizing condtion attribute" << endl;
		exit(EXIT_FAILURE);
	}
	delete attr;
}

condClass::~condClass() {
	if (pthread_cond_destroy(mCond)) {
		cout << "Error in destroying condtion" << endl;
		exit(EXIT_FAILURE);
	}
	delete mCond;
}

void condClass::wait(void* obj) {
	Mutex* tmpMutex = static_cast<Mutex*>(obj);
	if (pthread_cond_wait(mCond, tmpMutex->mMutex)) {
		cout << "Error in condtion wait" << endl;
		exit(EXIT_FAILURE);
	}
}

void condClass::publish(void* obj) {
	condClass* tmpObj = static_cast<condClass*>(obj);
	tmpObj->publish();
}

void condClass::publish() {
	if (pthread_cond_signal(mCond)) {
		cout << "Error in condtion wait" << endl;
		exit(EXIT_FAILURE);
	}
}

void condClass::publishAll() {
	if (pthread_cond_broadcast(mCond)) {
		cout << "Error in condtion wait" << endl;
		exit(EXIT_FAILURE);
	}
}

}