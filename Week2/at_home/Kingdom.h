/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File w2_at_home.cpp
// Version 2.0
// Date Feb 1, 2018
// Author 
// Student Cindy Chen
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace
namespace sict {

// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};

// TODO: declare the function display(...),
//         also in the sict namespace
	void display(sict::Kingdom& kingdom);
	void display(sict::Kingdom kingdom[], int num);
}
#endif // !SICT_KINGDOM_H