//! \file    videoDisplay.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files display the frame
//!

#ifndef VIDEO_DISPLAY_HPP
#define VIDEO_DISPLAY_HPP

#include <opencv2\opencv.hpp>


	
	class videoDisplay {
		public:
		
			videoDisplay();
			~videoDisplay();
		
			bool show(cv::Mat frame, const char* windowName);
			
	};
	


#endif