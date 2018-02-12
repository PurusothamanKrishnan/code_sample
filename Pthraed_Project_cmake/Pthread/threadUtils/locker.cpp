/*=============================================================================
start of file
=============================================================================*/

//! \file    Mutex.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   locker implementation (Pthread)
//!
//---------------------------------------------------------------------------  
#include "locker.hpp"

namespace threading
{
	template <typename T>
	locker<T>::locker(T& mutex)
		: mLockableObject(mutex)
	{
		mLockableObject.lock();
	}

	template <typename T>
	locker<T>::~locker(void)
	{
		mLockableObject.unlock();
	}

	void templateSpeclizeFunction() {
		Mutex tmp;
		locker<Mutex> var(tmp);
	}
}