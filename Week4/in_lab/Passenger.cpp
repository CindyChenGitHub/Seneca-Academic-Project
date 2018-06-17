/**********************************************************
// Workshop 4: 
// Passenger.cpp
// Student Name : Cindy Chen
// Date: 2018/02/12
**********************************************************/
// TODO: add file header comments here
// Passenger.cpp
#define _CRT_SECURE_NO_WARNINGS

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;
using namespace sict;

namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		strncpy(passengerName, "", Size);
		strncpy(destination, "", Size);
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination_) {
		if (name == nullptr || name[0] == '\0' ) {
			strncpy(passengerName, "", Size);
		}
		else {
			strncpy(Passenger::passengerName, name, Size);
		}
		if (destination_ == nullptr || destination_[0] == '\0')
			strncpy(destination, "", Size);
		else
			strncpy(Passenger::destination, destination_, Size);
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool result= passengerName == nullptr || passengerName[0]=='\0' || destination == nullptr || destination[0]=='\0';
		return result;
	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (Passenger::isEmpty())
			cout << "No passenger!" << endl;
		else
			cout << passengerName << " - " << destination << endl;
	}
}