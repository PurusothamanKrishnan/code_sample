/*=============================================================================
start of file
=============================================================================*/

//! \file    imageCorrection.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   display image after reading from video
//!
//---------------------------------------------------------------------------  

#include <iostream>
#include "imageCorrection.hpp"

namespace framework {
	imageCorrection::imageCorrection() {
		mNumElements = MAX_NUM_ELEMENTS;
		Elements = new double[mNumElements];
	}
	imageCorrection::~imageCorrection() {
		if (Elements != NULL) {
			delete Elements;
			Elements = NULL;
		}
	}

	void imageCorrection::init() {
		setIdentifier("imageCorrection");
		for (int i = 0; i < mNumElements; i++) {
			Elements[i] = i;
		}
	}

	void imageCorrection::processArgs(int argc, const char* argv[]) {
		mVideoInput.parseCommandLineArgs(argc, argv, getCamNum());
		mVideoInput.openVideo();
	}

	bool imageCorrection::run() {
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