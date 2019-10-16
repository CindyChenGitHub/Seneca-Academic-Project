// Workshop 5 - Lambda Expression
// Grades.h
// Yue Chen
// 2018-06-28
#pragma once
#include <fstream>
#include <string>
namespace sict {
    class Grades {
        std::string* c_studentNum;
        double* c_grade;
        int c_fileLines;
    public:
        Grades();
        Grades(char* _fileName);

        Grades(const Grades& _grades);
        Grades& operator = (const Grades& _grades);

        Grades(Grades&& _grades);
        Grades&& operator = (Grades&& _grades);

        template <typename F>
        void displayGrades(std::ostream& os, F _func) {      //func is the reference of the lambda expressions
            for (int i = 0; i < c_fileLines; i++) {
                os << c_studentNum[i] << " " << c_grade[i] << " ";
                os << _func(c_grade[i]) << std::endl;
            }
        }
        ~Grades();
    };
}