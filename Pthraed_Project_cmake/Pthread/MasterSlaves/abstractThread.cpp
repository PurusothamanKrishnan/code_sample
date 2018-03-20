/*=============================================================================
start of file
=============================================================================*/

//! \file    abstractThread.cpp
//! \author  Purusothaman Krishnan
//! \date    09-02-2018
//!
//! \brief   abstractThread class implementation
//!
//---------------------------------------------------------------------------   


#include "abstractThread.hpp"

namespace framework {
	void abstractThreadClass::setIdentifier( std::string id) {
		threadName.assign(id);
	}

	std::string abstractThreadClass::getIdentifier() {
		return threadName;
	}

}