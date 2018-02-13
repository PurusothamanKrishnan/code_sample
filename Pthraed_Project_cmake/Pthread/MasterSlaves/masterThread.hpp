//! \file    masterThreadFunction.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files implements master class which will launch all other child threads
//!

#include <childThread.hpp>
#include <map>
#include <mutex.hpp>
#include <conditionWrapper.hpp>
namespace framework {

	class masterThreadClass {
		public:
			typedef framework::childThreadClass childThreadClassType;
			typedef std::map<std::string, childThreadClassType*> threadsList;
			typedef std::pair<std::string, childThreadClassType*> pairType;
			masterThreadClass();
			~masterThreadClass();
			

			void addThreadToRunList(void* obj);
			
			void launchThreads();

			void waitForCompletion(void* obj);

			void waitForCompletion();

	    private:

			void launch();

			threading::Mutex mMutex;
			threading::condClass mCond;
			threadsList mRunnableThreads;
			int mNumChildThreads;
			bool mFirstTime;
	};

}