//! \file    imageRight.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files to correct the input image and read video
//!

#ifndef IMAGE_RIGHT_HPP
#define IMAGE_RIGHT_HPP

#include "childThread.hpp"
#include <opencv2\opencv.hpp>
#include <videoInput.hpp>
#include <videoDisplay.hpp>
using namespace cv;
#define MAX_NUM_ELEMENTS 1000;
namespace framework {
	
	class imageRight:public childThreadClass {
		public:
			typedef childThreadClass BaseClass;
			imageRight();
			~imageRight();
			
			void init();

			void processArgs(int argc, const char* argv[]);
			
			bool run();	
		private:			
			int mNumElements;
			double* Elements;
			videoInputReader mVideoInput;
			videoDisplay mVideoDisplay;
	};
	
}

#endif