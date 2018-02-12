/* ============================================================================
* Introduction to Operating Systems
* CS 8803, GT OMSCS
*
* Unauthorized copying of this file, via any medium is strictly prohibited.
*
* "priority-readers-and-writers.c"
* Implements the "Priority Readers and Writers" in Problem Set 1.
============================================================================ */

#include <pthread.h>
#include <iostream>
#include <cstdlib>
#include "sharedMutex.hpp"
#include "locker.hpp"
#include "threadWrapper.hpp"

using namespace std;
using namespace threading;

#define  MAX_NUM_ELEMENTS 20
#define READER_WRITER 0

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
int main(int argc, char **argv) {
	
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
