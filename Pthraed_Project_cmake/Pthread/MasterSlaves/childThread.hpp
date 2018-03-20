//! \file    masterThreadFunction.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files implements master class which will launch all other child threads
//!
#ifndef CHILD_THREAD_HPP
#define CHILD_THREAD_HPP
#include "abstractThread.hpp"
#include "masterThread.hpp"
#include "threadWrapper.hpp"
#include "conditionWrapper.hpp"
#include "mutex.hpp"

namespace framework {

	class childThreadClass:public abstractThreadClass {
		
		public:
			typedef framework::masterThreadClass masterClassType;
			childThreadClass();
			~childThreadClass();

			virtual void launch(void* args);

			void setCallBackFunction(void* (*func)(void*), void* args);

			static void* runFunction( void* args);
			
			virtual bool run();

			void run(void* args);
	

			virtual void subscribe(void * args);

			void waitForMaster();

			void publish();

			void setCamNum(int camNum) {
				mCamNum = camNum;
			}

			int getCamNum() {
				return mCamNum;
			}
		private:

			void* (*mFunc)(void*);
			void* mArgs;
			masterClassType* mMasterObj;
			threading::threadClass mThread;
			threading::Mutex mMutex;
			threading::condClass mCond;
			bool mIsRunning;
			int mCamNum;
	};
}

#endif