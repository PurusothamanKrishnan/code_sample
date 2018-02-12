//! \file    conditionWrapper.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files declares condition variable pthraedClass
//!

#ifndef CONDITION_WRAPPER_HPP
#define CONDITION_WRAPPER_HPP

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <pthread.h>

//---------------------------------------------------------------------------
// #defines
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// forward declaration
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// declaration
//---------------------------------------------------------------------------
namespace threading {
	class condClass {
		public:
			condClass();
			~condClass();
			void wait(void *);
			void publish(void *obj);
			void publishAll();
			void publish();
	    private:
			pthread_cond_t * mCond;
	};
}

#endif 