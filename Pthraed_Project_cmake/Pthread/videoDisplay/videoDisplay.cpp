/*=============================================================================
start of file
=============================================================================*/

//! \file    videoDisplay.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   video display interface class
//!
//---------------------------------------------------------------------------  

#include "videoDisplay.hpp"


	videoDisplay::videoDisplay() {
		
	}
	videoDisplay::~videoDisplay() {
		
	}

	bool videoDisplay::show(cv::Mat frame, const char* windowName) {
		if (frame.empty()) {
			return false;
		}
		imshow(windowName, frame);
		char val = (char)cv::waitKey(1);
		if (val == 27)  {
			return false;
		}
	}
