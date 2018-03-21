/**********************************************************
// Workshop 4: 
// Passenger.h
// Student Name : Cindy Chen
// Date: 2018/02/12
**********************************************************/
// TODO: add file header comments here
// Passenger.h
#define _CRT_SECURE_NO_WARNINGS

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define	SICT_PASSENGER_H
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	const int Size = 32;
	class Passenger {
		char passengerName[Size];
		char destination[Size];
	public:
		Passenger();
		Passenger(const char* name, const char* destination_);
		bool isEmpty() const;
		void display() const;
	};
}
#endif