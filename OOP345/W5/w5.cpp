// Workshop 5 - Lambda Expression
// w5.cpp
// Chris Szalwinski
// 2018-05-23

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
    std::cout << "Command Line : ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;

    if (argc == 1) {
        std::cerr <<
            "\n*** Insufficient number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << "\n*** Too many arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 2;
    }
    else {
        try {
            sict::Grades grades(argv[1]);
            // lambda expression for converting to letter
            auto letter = [](double _grade) {
                if (_grade >= 90) return getLetter(Ap);
                else if (_grade >= 80) return getLetter(Letter::A);
                else if (_grade >= 75) return getLetter(Letter::Bp);
                else if (_grade >= 70) return getLetter(Letter::B);
                else if (_grade >= 65) return getLetter(Letter::Cp);
                else if (_grade >= 60) return getLetter(Letter::C);
                else if (_grade >= 55) return getLetter(Letter::Dp);
                else if (_grade >= 50) return getLetter(Letter::D);
                else return  getLetter(Letter::F);
            };
            grades.displayGrades(std::cout, letter);
        }
        catch (const char* msg) {
            // report the error message
            std::cerr << argv[0] << ": Failed to open file "
                << argv[1] << "\n";
            return 2;
        }
    }
}