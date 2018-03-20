//! \file    threadWrapper.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files includes all common headers required for the module
//!

#ifndef THREAD_WRAPPER_HPP
#define THREAD_WRAPPER_HPP

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

	typedef struct threadInfo {
		pthread_t tID;
		void* (*tFunc) (void*);
		void* args;
		pthread_attr_t * attr;
	} threadParams;


	class threadClass {
		public:
			threadClass();
			threadClass(void *(*func)(void*), void* args);
			threadClass(void *(*func)(void*), void* args, pthread_attr_t* attrs);
			~threadClass();

			void initThreadParams(void *(*func)(void*), void* args);
			void createThread(void* params);
			void createThread();
			void joinThreads(void* args);
			pthread_t getThreadID() {
				return mThreadInfo->tID;
			}
		private:
			threadParams* mThreadInfo;
	};
}

#endif