/*=============================================================================
start of file
=============================================================================*/

//! \file    main.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   main file - start of the program
//!
//--------------------------------------------------------------------------- 

#include <pthread.h>
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include "masterThread.hpp"
#include "imageCorrection.hpp"
#include "imageDisplay.hpp"
#include "imageFront.hpp"
#include "imageRight.hpp"

using namespace std;
using namespace threading;

#define  MAX_NUM_ELEMENTS 20
#define READER_WRITER 0
#define MASTER_THREAD_IMPL 1
#if READER_WRITER
int arr[20];
int numElements = 0;
int val = 100;
int index = 0;

struct objList {
	sharedMutex readerLock;
	sharedMutex writerLock;
};
void* writer(void* args) {
	objList* tmpObj = static_cast<objList*>(args);
	while (1) {
		tmpObj->writerLock.mutexLock();
		if (numElements > 0) {
			tmpObj->writerLock.wait();
		}
		if (index == MAX_NUM_ELEMENTS) {
			tmpObj->writerLock.mutexUnLock();
			return 0;
		}
		arr[index] = val;
		val++;
		cout << "Writer:" << arr[index] << endl;
		index++;
		numElements++;
		tmpObj->writerLock.mutexUnLock();
		tmpObj->readerLock.publish();
	}
	return 0;
	

}
void* reader(void* args) {
	objList* tmpObj = static_cast<objList*>(args);
	for (int i = 0; i < 20; i++) {
		tmpObj->readerLock.mutexLock();
		if (numElements == 0) {
			tmpObj->readerLock.wait();
		}
		numElements--;
		cout << "Reader:"<<arr[index - 1] << endl;
		tmpObj->readerLock.mutexUnLock();

		tmpObj->writerLock.publish();
	}
	return 0;
}
#endif
int main(int argc, const char *argv[]) {

#if MASTER_THREAD_IMPL
	framework::masterThreadClass masterObj;
	framework::imageCorrection imgCrtnObj;
	framework::imageDisplay imgDslyObj;
	framework::imageFront imgFrnt;
	framework::imageRight imgRigt;

	imgCrtnObj.init();
	imgDslyObj.init();
	imgFrnt.init();
	imgRigt.init();

	imgCrtnObj.setCamNum(0);
	imgDslyObj.setCamNum(1);
	imgFrnt.setCamNum(2);
	imgRigt.setCamNum(3);

	imgCrtnObj.processArgs(argc, argv);
	imgDslyObj.processArgs(argc, argv);
	imgFrnt.processArgs(argc, argv);
	imgRigt.processArgs(argc, argv);
	
	
	
	imgCrtnObj.subscribe(&masterObj);
	imgDslyObj.subscribe(&masterObj);
	imgFrnt.subscribe(&masterObj);
	imgRigt.subscribe(&masterObj);
	masterObj.startAllThreads();
	while(masterObj.isRunning()) {
		Sleep(1);
	}

#endif

#if READER_WRITER
	objList mutexs;

	threadClass threadOne;
	threadClass threadTwo;
	threadOne.initThreadParams(writer, &mutexs);
	threadTwo.initThreadParams(reader, &mutexs);
	threadOne.createThread();
	threadTwo.createThread();
	threadOne.joinThreads(&threadOne);
	threadTwo.joinThreads(&threadTwo);
#else
	cout << "Sample Code"<<endl;
#endif
	return 0;
}
