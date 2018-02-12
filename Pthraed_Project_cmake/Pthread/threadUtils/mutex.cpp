/*=============================================================================
start of file
=============================================================================*/

//! \file    Mutex.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   mutex implementation (Pthread)
//!
//---------------------------------------------------------------------------  
#include <iostream>
#include "mutex.hpp"
using namespace std;
namespace threading {
	
	Mutex::Mutex() {
		pthread_mutexattr_t attr;
		mMutex = (pthread_mutex_t *) new pthread_mutex_t;
		mLocked = false;
		if (pthread_mutexattr_init(&attr))  {
			cout << "Error in initilizing the mutex attr" << endl;
		}

		if (pthread_mutex_init(mMutex, &attr)) {
			cout << "Error in creating the mutex" << endl;
		}
	}

	Mutex::~Mutex() {
		int ret = pthread_mutex_destroy(mMutex);
		if (ret) {
			cout << "Error in deleting the mutex" << endl;
		}
	}

	void Mutex::lock() {
		if (pthread_mutex_lock(mMutex)) {
			cout << "Error in locking the mutex" << endl;
		}
		mLocked = true;
	}

	void Mutex::unlock() {
		mLocked = false;
		if (pthread_mutex_unlock(mMutex)) {
			cout << "Error in unlocking the mutex" << endl;
		}
	}

	void Mutex::asynclock() {
		pthread_mutex_trylock(mMutex);
		mLocked = true;
	}

}