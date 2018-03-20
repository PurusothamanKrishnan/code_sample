/*=============================================================================
start of file
=============================================================================*/

//! \file    videoInput.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   video input interface class
//!
//---------------------------------------------------------------------------  

#include <iostream>
#include "videoInput.hpp"
#include <algorithm>
#include <map>
#include <stdio.h>
#include <cstdarg>

void WriteFormatted(const char * format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

	videoInputReader::videoInputReader() {
		mCamNum = 999;
		mFrameValid = true;
	}
	videoInputReader::~videoInputReader() {

	}

	void videoInputReader::parseCommandLineArgs(const int agrC,const char * argV[],int camNum) {

		char buff[128];
		char tmpBuff[20];
		
		if (camNum == 999) {
			std::cout << "Cam Num is not defined: rear view Selected" << std::endl;
			camNum = 0;
		}
		else if (camNum > 4){
			std::cout << "Cam Num is invalid: rear view Selected" << std::endl;
			camNum = 0;
		}

		_snprintf(tmpBuff, 20,"camname%d", camNum);
		_snprintf(buff, 128, "{ videoPath | | input video path } {camname%d | | camera name}", camNum);
		cv::String keyMap = buff;
		cv::CommandLineParser parser(agrC, argV, keyMap);
		parser.printMessage();
		mInputFilePath = parser.get<cv::String>("videoPath");
		mCamName = parser.get<cv::String>(tmpBuff);
	}

	void videoInputReader::changeCamName(std::string camName) {
		mCamName = camName;
	}

	void videoInputReader::setInputPath(std::string path) {
		mInputFilePath = path;
	}

	void videoInputReader::setCamType(int camNum) {
		if (mCamNum == 999) {
			mCamNum = camNum;
		}
		else {
			std::cout << "Cam type is already defined" << std::endl;
		}
	}

	void videoInputReader::openVideo() {
		std::map<int,std::string> camNameToNum = {
			{ 0 , "BV" },
			{ 1 , "FV" },
			{ 2 , "LV" },
			{ 3 , "RV" }
		};
		std::map<int, std::string>::iterator it;
		int camNum = 999;
		for (it = camNameToNum.begin(); it != camNameToNum.end(); it++) {
			if (!std::strcmp(it->second.c_str(), mCamName.c_str())) {
				camNum = it->first;
			}
		}
		std::string camName[] = {
			"cam_rear.avi", "cam_front.avi", "cam_left.avi", "cam_right.avi"
		};
		std::string finalPath;
		if (camNum != 999) {
			std::string tmp = "\\" + camName[camNum];
			finalPath = mInputFilePath + tmp;

			mVideoInput.open(finalPath);
			if (!mVideoInput.isOpened()) {
				std::cout << "Error Reading Video" << std::endl;
				exit(EXIT_FAILURE);
			}

		}
		else {
			std::cout << "Define camera type first:" << std::endl;
			std::cout << "BV: Rear Camera" << std::endl;
			std::cout << "FV: Front Camera" << std::endl;
			std::cout << "LV: Left Camera" << std::endl;
			std::cout << "RV: Right Camera" << std::endl;
		}
		
	}

	cv::Mat videoInputReader::grabFrame() {
		cv::Mat frame;
		mVideoInput >> frame;

		if (frame.empty())
			mFrameValid = false;
		return frame;
	}
