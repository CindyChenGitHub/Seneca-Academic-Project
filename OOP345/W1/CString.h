// Course: OOP345 C++
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Student: Cindy
// Date: May 18, 2018
// CString.h

#pragma once    

namespace sict {
    const int MAX_CHAR = 14;		// exclude null.
	
    class CString {
        char c_string[MAX_CHAR + 1];
	static int RECORD_COUNTER; 	
    public:
        CString(const char* _string = nullptr);
        void display(std::ostream& os) const;
    };
    std::ostream& operator<< (std::ostream& os, const CString& _cstring);
}
