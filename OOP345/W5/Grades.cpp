// Workshop 5 - Lambda Expression
// Grades.cpp
// Yue Chen
// 2018-06-28
#include<iostream>
#include<fstream>
#include<string>
#include "Grades.h"
using namespace sict;
Grades::Grades() :c_studentNum(nullptr), c_grade(nullptr), c_fileLines(0) {}
Grades::Grades(char* _fileName) {
    try {
        std::ifstream input(_fileName);
        if (input) {
            std::string tempStr;
            c_fileLines = 0;

            while (!input.eof()) {
                getline(input, tempStr);
                if (tempStr != "")
                    c_fileLines++;
            }
            input.clear();
            input.seekg(0);
            c_studentNum = new std::string[c_fileLines];
            c_grade = new double[c_fileLines];
            for (int i = 0; i < c_fileLines; i++) {
                input >> c_studentNum[i];
                input >> c_grade[i];
                input.ignore(2000, '\n');
            }
        }
        input.close();
    }
    catch (std::bad_alloc) {
        throw ("Insufficient memory");
    }
}

Grades::Grades(const Grades& _grades) {
    *this = _grades;
}
Grades& Grades::operator = (const Grades& _grades) {
    if (this != &_grades) {
        delete[] c_studentNum;
        delete[] c_grade;
        c_studentNum = new std::string[_grades.c_fileLines];
        c_grade = new double[_grades.c_fileLines];
        c_studentNum = _grades.c_studentNum;
        c_grade = _grades.c_grade;
        c_fileLines = _grades.c_fileLines;
    }
    return *this;
}

Grades::Grades(Grades&& _grades) {
    *this = std::move(_grades);
}

Grades&& Grades::operator  = (Grades&& _grades) {
    if (this != &_grades) {
        c_studentNum = _grades.c_studentNum;
        c_grade = _grades.c_grade;
        c_fileLines = _grades.c_fileLines;
        _grades.c_studentNum = nullptr;
        _grades.c_grade = nullptr;
        _grades.c_fileLines = 0;
    }
    return std::move(*this);
}

Grades::~Grades() { delete[] c_studentNum; delete[] c_grade; }

/*template<typename F>
void Grades::displayGrades(std::ostream& os, Grades<F> _func) {
    for (int i = 0; i < c_fileLines; i++) {
        os << c_studentNum[i] << " " << c_grade[i] << " ";
        os << _func(c_grade[i]) << std::endl;
    }
    
}*/