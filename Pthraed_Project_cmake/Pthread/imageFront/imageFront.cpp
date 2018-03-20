/*=============================================================================
start of file
=============================================================================*/

//! \file    imageDisplay.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   display image after reading from video
//!
//---------------------------------------------------------------------------  


#include "imageFront.hpp"
#include <iostream>

namespace framework {
	imageFront::imageFront() {
		mNumElements = MAX_NUM_ELEMENTS;
		Elements = new double[mNumElements];
	}
	imageFront::~imageFront() {
		if (Elements != NULL) {
			delete Elements;
			Elements = NULL;
		}
	}

	void imageFront::init() {
		setIdentifier("imageFront");
		for (int i = 0; i < mNumElements; i++) {
			Elements[i] = i;
		}
	}

	void imageFront::processArgs(int argc, const char* argv[]) {
		mVideoInput.parseCommandLineArgs(argc, argv, getCamNum());
		mVideoInput.openVideo();
	}

	bool imageFront::run() {

#if 0
		while
		for (int i = 0; i < mNumElements; i++) {
			for (int j = 0; j < mNumElements; j++) {
				Elements[i] = Elements[i] + Elements[j];
				
			}
			std::cout << "imageDisplay:" << i << std::endl;
		}
#else
		Mat frame;
		while (1) {
			frame = mVideoInput.grabFrame();
			if (!mVideoInput.isFrameValid()) {
				break;
			}

			if (!mVideoDisplay.show(frame, getIdentifier().c_str())) {
				break;
			}
		}
#endif
		return true;
	}
}