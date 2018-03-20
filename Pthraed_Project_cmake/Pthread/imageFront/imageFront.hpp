//! \file    imageFront.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files to display image and read video
//!

#ifndef IMAGE_FRONT_HPP
#define IMAGE_FRONT_HPP

#include "childThread.hpp"
#include <videoInput.hpp>
#include <videoDisplay.hpp>
#include <opencv2\opencv.hpp>
using namespace cv;
#define MAX_NUM_ELEMENTS 1000;
namespace framework {
	
	class imageFront:public childThreadClass {
		public:
			typedef childThreadClass BaseClass;
			imageFront();
			~imageFront();
			
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