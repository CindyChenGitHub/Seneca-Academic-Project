// Final Project Milestone 5
// Version 1.0
// Date.h
// -----------------------------------------------------------
//Student:  Yue Chen    Date: 2018-04-15
////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'

#include <iostream>
namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;
	const int NO_ERROR = 0;		// No error - the date is valid
	const int CIN_FAILED = 1;	// istream failed on information entry
	const int YEAR_ERROR = 2;	// Invalid Year in Date Entry
	const int MON_ERROR = 3;	// Invalid Month in Date Entry
	const int DAY_ERROR = 4;	// Invalid Day in Date Entry

  class Date {
	long c_year;
	long c_month;
	long c_day;         // February has 29 days in a leap year.
	int c_comValue;     // use to compare two date.
	int c_errState;     // Error state code.

    int mdays(int month, int year)const;	//the number of days in month of year.
	void errCode(int errCode);	// sets the error state variable to one of the values listed.
 
  public:
	Date();                                     // Default constructor, set to safe empty and no error state.
	Date( int year, int month, int day);        // Three argument constructor. Accepts and checks dates, or set error states. 
    ~Date();                                    // Destructor function
    bool operator== (const Date& rhs) const;    // Operator funcation to compare dates.
	bool operator!= (const Date& rhs) const;    // Operator funcation to compare dates.
	bool operator< (const Date& rhs) const;     // Operator funcation to compare dates.
	bool operator> (const Date& rhs) const;     // Operator funcation to compare dates.
	bool operator<= (const Date& rhs) const;    // Operator funcation to compare dates.
	bool operator>= (const Date& rhs) const;    // Operator funcation to compare dates.
	int errCode() const;                        // get errCode.
	bool bad() const;                           // return true if there is error.
	void read(std::istream& istr);              // Get date.
	void write(std::ostream& ostr) const;       // Display date.
};
	std::ostream& operator<<(std::ostream& ostr, const Date& wdate);    // Helper operat0r funcation to display date.
	std::istream& operator>>(std::istream& istr, Date& rdate);          // Helper operat0r funcation to set date.
}
#endif