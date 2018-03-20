/*=============================================================================
start of file
=============================================================================*/

//! \file    imageRight.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   display image after reading from video
//!
//---------------------------------------------------------------------------  

#include <iostream>
#include "imageRight.hpp"

namespace framework {
	imageRight::imageRight() {
		mNumElements = MAX_NUM_ELEMENTS;
		Elements = new double[mNumElements];
	}
	imageRight::~imageRight() {
		if (Elements != NULL) {
			delete Elements;
			Elements = NULL;
		}
	}

	void imageRight::init() {
		
		setIdentifier("imageRight");
		for (int i = 0; i < mNumElements; i++) {
			Elements[i] = i;
		}
	}

	void imageRight::processArgs(int argc, const char* argv[]) {
		mVideoInput.parseCommandLineArgs(argc, argv, getCamNum());
		mVideoInput.openVideo();
	}

	bool imageRight::run() {
#if 0
		for (int i = 0; i < mNumElements; i++) {
			for (int j = 0; j < mNumElements; j++) {
				Elements[i] = Elements[i] + Elements[j];
			}
			std::cout << "imageCorrection i:" << i << std::endl;
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