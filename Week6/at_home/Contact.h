// Workshop 6 - Class with a Resource
// w6_at_home.cpp
// Yue Chen
// 2018/03/18

#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H


namespace sict{
	const int Max_Name = 20;
	class Contact{
		char c_name[Max_Name];
		long long* c_phoneNums;
        int c_nums;

	public:
		Contact();
		Contact(const char* name, const long long* phoneNums, const int nums);
        Contact(const Contact& contact);
        Contact& operator=(const Contact& contact_);
        Contact& operator+=(const long long newPhonenum);
        ~Contact();
		bool isEmpty() const;
		void display() const;
	};
}

#endif