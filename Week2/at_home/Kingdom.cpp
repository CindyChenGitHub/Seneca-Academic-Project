/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 2.0
// Date Feb 1, 2018
// Author 
// Student Cindy Chen
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
	
	void display(sict::Kingdom kingdom[], int num){
		int totalPopulation = 0;
		cout << "------------------------------" << endl << "Kingdoms of SICT" << endl << "------------------------------" << endl;
		for (int i=0; i<num; i++){
			totalPopulation += kingdom[i].m_population;
            cout << i + 1 << ". ";
            display(kingdom[i]);
		}
		cout << "------------------------------" << endl << "Total population of SICT: " << totalPopulation << endl << "------------------------------" << endl;
	}
}
