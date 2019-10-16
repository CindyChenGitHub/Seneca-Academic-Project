// Course: OOP345 C++
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Student: Cindy
// Date: May 18, 2018
// CString.cpp

#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include "CString.h"

namespace sict {
	int RECORD_COUNTER { 10 }; 
	
	// constructor of CString class, default to empty
	CString::CString(const char* _string) {
		int length = strlen(_string) < (MAX_CHAR) ? strlen(_string) : (MAX_CHAR); 
		strncpy(c_string, _string, length);	
		c_string[length] = '\0';
	}

	// member function to display CString class
	void CString::display(std::ostream& os) const {
		int i = 0;
		while (c_string[i] != '\0')
			os << c_string[i++];
	}

	// non-friend helper operator to display received CString type object  
	std::ostream& operator<< (std::ostream& os, const CString& _cstring) {
		std::cout << " " << RECORD_COUNTER++ << ": ";
		_cstring.display(os);
		return os;
	}
}
