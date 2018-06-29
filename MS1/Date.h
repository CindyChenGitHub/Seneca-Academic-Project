// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name         Date         Reason
//////////////////////////////////////////////////////////////
//Student:
//--------------------------------
//Name: YC    Date: 2018-03-13
////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;
	const int NO_ERROR = 0;		// No error - the date is valid
	const int CIN_FAILED = 1;	// istream failed on information entry
	const int YEAR_ERROR = 2;	// Year value is invalid
	const int MON_ERROR = 3;	// Month value is invalid
	const int DAY_ERROR = 4;	// Day value is invalid

  class Date {
	long c_year;
	long c_month;
	long c_day;
	int c_comValue;
	int c_errState;

    int mdays(int month, int year)const;	//the number of days in month of year.
	void errCode(int errCode);	// sets the error state variable to one of the values listed.
 
  public:
	Date();
	Date( int year, int month, int day);
	bool operator== (const Date& rhs) const;
	bool operator!= (const Date& rhs) const;
	bool operator< (const Date& rhs) const;
	bool operator> (const Date& rhs) const;
	bool operator<= (const Date& rhs) const;
	bool operator>= (const Date& rhs) const;
	int errCode() const;
	bool bad() const;
	void read(std::istream& istr);
	void write(std::ostream& ostr) const;
};
	std::ostream& operator<<(std::ostream& ostr, const Date& wdate);
	std::istream& operator>>(std::istream& istr, Date& rdate);
}
#endif