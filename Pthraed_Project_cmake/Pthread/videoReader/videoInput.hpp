//! \file    imageRight.hpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   Header Files to read video
//!

#ifndef VIDEO_INPUT_HPP
#define VIDEO_INPUT_HPP

#include <opencv2\opencv.hpp>
#include <cstring>


	class videoInputReader {
		public:
		    const int maxNumCharsPath = 1000;

			typedef struct camName {
				int camNum;
				std::string cameraName;
			} camInfoType;
			
			videoInputReader();
			~videoInputReader();
			
			void setInputPath(std::string path);
			
			void setCamType(int camNum);

			void parseCommandLineArgs(const int agrC,const char * argV[],int camNum);

			void openVideo();
			
			void changeCamName(std::string camName);

			cv::Mat grabFrame();

			bool isFrameValid() {
				return mFrameValid;
			}
				
			
		private:	
	        std::string getCamName();
			
			std::string mInputFilePath;
			std::string mCamName;
			int mCamNum;
			bool mFrameValid;
			
			cv::VideoCapture mVideoInput;
	};	


#endif