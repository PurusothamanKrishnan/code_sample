//! \file    abstractThread.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   abstract class implementaion for thread
//!

#ifndef ABSTRACT_THREAD_HPP
#define ABSTRACT_THREAD_HPP

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <pthread.h>
#include <string>
//---------------------------------------------------------------------------
// #defines
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// forward declaration
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// declaration
//--------------------------------------------------------------------------- 

namespace framework {
	class abstractThreadClass {
		public:
			
			virtual void launch(void* args) = 0;

			virtual void publish() = 0;

			void setIdentifier(std::string id);

			std::string getIdentifier();
	    private:
			std::string threadName;		
	};

}
#endif