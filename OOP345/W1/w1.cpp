// Course: OOP345 C++
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Student: Cindy
// Date: May 18, 2018
// w1.cpp
// Command Arguments in VS:  right click project (not solution) -> Propertres -> Configeration Properties -> Debugging -> Command Arguments -> "w1 Conurees.dat"

#pragma warning( disable:4996 )
#include <iostream>
#include <fstream>
#include "345_w1_Process.h"
#include "CString.h"

int main(int argc, char* argv[]) {

    // To print out command arguments like " Command Line : w1 Courses.dat "
    std::cout << "Command Line : ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;

    // To check command arguments, and give erron infomation.
    if (argc < 3) {
        std::cout << "*** Insufficient number of arguments ***" << std::endl << "Usage: w1 filename" << std::endl;
        return 1;
    }
    else if (argc > 3) {
        std::cout << "*** Too many arguments ***" << std::endl << "Usage: w1 filename" << std::endl;
        return 1;
    }
    else {

        // Open file
        std::ifstream fin(argv[2]);

        if (fin) {
            std::cout << "Reading records from file " << argv[2] << std::endl;
            std::cout << " No Record Contents ..." << std::endl;

            // get strings from file and access by function
            while (!fin.eof()) {
                char strtemp[sict::MAX_CHAR + 1];
                fin.get(strtemp, sict::MAX_CHAR + 1, '\n');
                fin.ignore(2000, '\n');
                process(strtemp);
            }
            
            return 0;
        }
        else {
            std::cout << "*** Failed to open file " << argv[2] << " ***" << std::endl;
            return 1;
        }
    }
}
