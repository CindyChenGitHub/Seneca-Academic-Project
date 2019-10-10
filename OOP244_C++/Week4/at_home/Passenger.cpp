/**********************************************************
// Workshop 4: Classes and Privacy
// Passenger.cpp
// Student Name : Cindy Chen
// Date: 2018/02/13
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
		strncpy(passengerName_c, "", Size-1);
        passengerName_c[Size - 1] = '\0';
		strncpy(destination_c, "", Size-1);
        destination_c[Size - 1] = '\0';
		yearDep_c = 0;
		monthDep_c = 0;
		dayDep_c = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
        if (name == nullptr || name[0] == '\0') {
			strncpy(passengerName_c, "", Size-1);
            passengerName_c[Size - 1] = '\0';
        }

        else {
			strncpy(passengerName_c, name, Size-1);
            passengerName_c[Size-1] = '\0';
        }

        if (destination == nullptr || destination[0] == '\0') {
			strncpy(destination_c, "", Size-1);
            destination_c[Size - 1] = '\0';
        }

        else {
			strncpy(destination_c, destination, Size-1);
            destination_c[Size - 1] = '\0';
        }

		if (name == nullptr || name[0] == '\0' || destination == nullptr || destination[0] == '\0'){
			yearDep_c = 0;
			monthDep_c = 0;
			dayDep_c = 0;
		}
		else{
			yearDep_c = 2017;
			monthDep_c = 7;
			dayDep_c = 1;
		}
	}
	Passenger::Passenger(const char* name, const char* destination, const int year, const int month, const int day){
        if (name == nullptr || name[0] == '\0') {
			strncpy(passengerName_c, "", Size-1);
            passengerName_c[Size - 1] = '\0';
        }
        else {
			strncpy(passengerName_c, name, Size-1);
            passengerName_c[Size - 1] = '\0';
        }
        if (destination == nullptr || destination[0] == '\0') {
			strncpy(destination_c, "", Size-1);
            destination_c[Size - 1] = '\0';
        }
        else {
			strncpy(destination_c, destination, Size-1);
            destination_c[Size - 1] = '\0';
        }
		if (year < 2017 || year > 2020)
			yearDep_c = 0;
		else
			yearDep_c = year;
		if (month < 1 || month >12)
			monthDep_c = 0;
		else
			monthDep_c = month;
		if (day < 1 || day > 31)
			dayDep_c = 0;
		else
			dayDep_c = day;
	}

    const char* Passenger::name() const {
		return passengerName_c;
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		return passengerName_c == nullptr || passengerName_c[0] == '\0' || destination_c == nullptr || destination_c[0] == '\0' || yearDep_c < 2017 || yearDep_c > 2020 || monthDep_c < 1 || monthDep_c >12 || dayDep_c < 1 || dayDep_c >31 ;
	}

	bool Passenger::canTravelWith(const Passenger& friends) const{
		return (!strcmp(this->destination_c , friends.destination_c) && (this->yearDep_c == friends.yearDep_c) && (this->monthDep_c == friends.monthDep_c) && (this->dayDep_c == friends.dayDep_c));
	}

	// TODO: implement display query here
	void Passenger::display() const {
		if (Passenger::isEmpty())
			cout << "No passenger!" << endl;
		else{
			cout << passengerName_c << " - " << destination_c << " on " << yearDep_c << "/";
			cout.fill('0');
			cout.width(2);
			cout << monthDep_c << "/" << dayDep_c << endl;
		}
	}
}