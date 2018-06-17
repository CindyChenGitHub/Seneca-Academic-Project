/**********************************************************
// Workshop 4: Classes and Privacy
// Passenger.h
// Student Name : Cindy Chen
// Date: 2018/02/13
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
		char passengerName_c[Size];
		char destination_c[Size];
        int yearDep_c;
        int monthDep_c;
        int dayDep_c;
	public:
		Passenger();
		Passenger(const char* name, const char* destination);
        Passenger(const char* name, const char* destination, const int year, const int month, const int day);
		const char* name() const;
		bool isEmpty() const;
		bool canTravelWith(const Passenger& friends) const;
		void display() const;
	};
}
#endif