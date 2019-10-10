/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date Jan 29, 2018
// Author Cindy Chen
***********************************************************/

// TODO: include the necessary headers
#include <iostream>
using namespace std;
// TODO: the sict namespace
#include "Kingdom.h"

namespace sict {
	// TODO:definition for display(...) 
	void display(sict::Kingdom& kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
}
