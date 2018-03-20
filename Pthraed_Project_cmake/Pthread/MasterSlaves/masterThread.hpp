//! \file    masterThreadFunction.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files implements master class which will launch all other child threads
//!
#ifndef MASTER_THREAD_HPP
#define MASTER_THREAD_HPP
#include <map>
#include "commonHeader.hpp"
namespace framework {

	class masterThreadClass {
		public:
			typedef void*(*THREADFUNCPTR)(void*);
			typedef threading::Mutex mutexType;
			typedef threading::condClass condType;
			typedef framework::abstractThreadClass childThreadClassType;
			typedef std::map<std::string, childThreadClassType*> threadsList;
			typedef std::pair<std::string, childThreadClassType*> pairType;
			masterThreadClass();
			~masterThreadClass();
			

			void addThreadToRunList(void* obj);
			
			void launchThreads();
			void notifyMasterThread();
			void notifyThreadCompleteStatus();
			bool updateThreadStatus();

			static void* waitForCompletion(void* obj);
			void waitForCompletion();
			void waitForChildThreads();
			void startAllThreads();

			void joinMasterThread();

			bool runAllThreads();

			bool isRunning() {
				return mIsRunning;
			}
			mutexType* getMutex() {
				return &mMutex;
			}
			condType* getCond() {
				return &mCond;
			}
	    private:

			void launch(void* args);
			
			threading::threadClass mMasterThreadObj;
			threading::Mutex mMutex;
			threading::Mutex mrunningThreadsMutex;
			threading::condClass mCond;
			threadsList mRunnableThreads;
			int mNumChildThreads;
			int nCompletedThreads;
			bool mFirstTime;
			bool mIsRunning;
	};

}

#endif