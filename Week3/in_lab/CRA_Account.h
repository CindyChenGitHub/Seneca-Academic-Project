/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.h
// Student Name : Cindy Chen
// Date: 2018/02/05
**********************************************************/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	class CRA_Account {

		char familyNameCRA[max_name_length];
		char givenNameCRA[max_name_length];
		int sinCRA;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}

#endif
