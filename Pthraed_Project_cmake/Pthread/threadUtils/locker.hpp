//! \file    locker.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files includes all common headers required for the module
//!

#ifndef LOCKER_HPP
#define LOCKER_HPP

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// #defines
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "mutex.hpp"
//---------------------------------------------------------------------------
// forward declaration
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// declaration
//---------------------------------------------------------------------------

namespace threading {


	template<typename T>
	class locker
	{
	public:

		locker(T& mutex);
		~locker(void);
	private:
		T& mLockableObject;
	};
	
	//template<typename T>
	//locker<T>::locker(T& mutex)
	//	: mLockableObject(mutex)
	//{
	//	mLockableObject.lock();
	//}

	//template<typename T>
	//locker<T>::~locker(void)
	//{
	//	mLockableObject.unlock();
	//}
}
#endif