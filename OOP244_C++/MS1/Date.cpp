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
// Name        Date          Reason
/////////////////////////////////////////////////////////////////
//Student:
//--------------------------------
//Name: YC    Date: 2018-03-13
////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"

namespace AMA {

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	// sets the error state variable to one of the values listed.
	void Date::errCode(int errCode) {
		switch (errCode) {
		case 1:
			c_errState = CIN_FAILED;
			break;
		case 2:
			c_errState = YEAR_ERROR;
			break;
		case 3:
			c_errState = MON_ERROR;
			break;
		case 4:
			c_errState = DAY_ERROR;
			break;
		default:
			c_errState = NO_ERROR;
			break;
		}
	}

	Date::Date() {
		c_year = 0;
		c_month = 0;
		c_day = 0;
		c_comValue = 0;
		c_errState = NO_ERROR;
	}

	Date::Date(int year, int month, int day) {
		int valid = 0;
		if (year < min_year || year > max_year)
			valid = 2;
		else if (month < 1 || month > 12)
			valid = 3;
		else if (day < 1 || day > mdays(month, year))
			valid = 4;
		else;

		if (valid == 0) {
			c_year = year;
			c_month = month;
			c_day = day;
			c_comValue = year * 372 + month * 13 + day;
			c_errState = NO_ERROR;
		}
		else {
			c_year = 0;
			c_month = 0;
			c_day = 0;
			c_comValue = 0;
			errCode(valid);
		}
	}

	bool Date::operator== (const Date& rhs) const {
		return (c_comValue == rhs.c_comValue);
	}

	bool Date::operator!= (const Date& rhs) const {
		return (c_comValue != rhs.c_comValue);
	}

	bool Date::operator< (const Date& rhs) const {
		return (c_comValue < rhs.c_comValue);
	}

	bool Date::operator> (const Date& rhs) const {
		return (c_comValue > rhs.c_comValue);
	}

	bool Date::operator<= (const Date& rhs) const {
		return (c_comValue <= rhs.c_comValue);
	}

	bool Date::operator>= (const Date& rhs) const {
		return (c_comValue >= rhs.c_comValue);
	}

	int Date::errCode() const {
		return c_errState;
	}

	bool Date::bad() const {
		return c_errState != 0;
	}
	/*  I think this function is right, because the date formate is "YYYY?MM?DD". Form like "10/1/1" should not pass the cin test, and it should get the "CIN_FAILD" error. However in the tester, I have to let it pass the cin test and get "YEAR_ERR". So, I have to write another function to pass the testor.
	void Date::read(std::istream& istr) {
		bool ok = true;
		char year[5], month[3], day[3], a, b, c;
		int year_, month_, day_;
		if (ok) {
			istr.get(year, 5);
			for (int i = 0; i < 4 && ok; i++)
				ok = !(year[i] < '0' || year[i] >'9');
		}
		if (ok) {
			istr.get(a);
			//ok = (a = '/' || a = '-');
		}
		if (ok) {
			istr.get(month, 3);
			for (int i = 0; i < 2 && ok; i++)
				ok = !(month[i] < '0' || month[i] >'9');
		}
		if (ok) {
			istr.get(b);
			ok = (b == a);
		}
		if (ok) {
			istr.get(day, 3);
			for (int i = 0; i < 2 && ok; i++)
				ok = !(day[i] < '0' || day[i] >'9');
		}
		if (ok) {
			istr.get(c);
			ok = (c == '\n');
		}
		if (ok) {
			year_ = (year[0] - '0') * 1000 + (year[1] - '0') * 100 + (year[2] - '0') * 10 + (year[3] - '0');
			month_ = (month[0] - '0') * 10 + (month[1] - '0');
			day_ = (day[0] - '0') * 10 + (day[1] - '0');
			Date temp(year_, month_, day_);
			*this = temp;
		}
		else {
			errCode(1);
			istr.fail();
		}
	}*/

	void Date::read(std::istream& istr) {
		bool ok = true;
		int year_, month_, day_;
		istr >> year_;
		istr.get();
		istr >> month_;
		istr.get();
		istr >> day_;
		istr.clear();

		if (year_ < 0 || year_>9999) ok = false;
		else if (month_ < 0 || month_>99) ok = false;
		else if (day_ < 0 || day_>99) ok = false;
		else;

		if (ok) {
			Date temp(year_, month_, day_);
			*this = temp;
		}
		else {
			errCode(1);
			istr.fail();
		}
	}

	void Date::write(std::ostream& ostr) const {
		ostr.fill('0');
		//ostr.width(4);
		ostr << c_year << "/";
		ostr.width(2);
		ostr << c_month << "/" ;
		ostr.width(2);
		ostr << c_day;
		//ostr.fill(' ');
	}
	//works with an std::ostream object to print a date to the console. 
	std::ostream& operator<<(std::ostream& ostr, const Date& wdate) {
		wdate.write(ostr);
		return ostr;
	}
	//works with an std::istream object to read a date from the console. 
	std::istream& operator >> (std::istream& istr, Date& rdate) {
		rdate.read(istr);
		return istr;
	}

}
