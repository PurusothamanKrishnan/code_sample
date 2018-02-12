//! \file    sharedMutex.h
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files includes all common headers required for the module
//!

#ifndef SHARED_MUTEX_HPP
#define SHARED_MUTEX_HPP

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// #defines
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "mutex.hpp"
#include "conditionWrapper.hpp"
//---------------------------------------------------------------------------
// forward declaration
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// declaration
//---------------------------------------------------------------------------
namespace threading {

class sharedMutex {
	public:
		sharedMutex();
		~sharedMutex();
		void wait();
		static void mutexLock();
		static void mutexUnLock();
		static void wait(void* obj);
		void publish(void* obj);
		void publish();
	private:
		static Mutex mSharedMutexObj;
		condClass mCond;
};

}

#endif