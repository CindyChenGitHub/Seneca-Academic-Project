// Final Project Milestone 2 - ErrorState Class
// Version 3.3
// ErrorState.cpp
// Date	2018-03-03
// Author	Chris Szalwinski, Fardad Soleimanloo
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// CS                 2017-10-11           Fall semester upgrade
// Chris              2018-03-02           Final Draft 20181
// Chris              2018-03-03           Message -> State
/////////////////////////////////////////////////////////////////
//Student:
//--------------------------------
//Name: Yue Chen    Date: 2018-03-21
////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'
#include<iostream>
#include<cstring>
#include"ErrorState.h"

using namespace std;
using namespace AMA;
namespace AMA {
    ErrorState::ErrorState(){
        c_message = nullptr;
    }

    ErrorState::ErrorState(const char* errorMessage) {
        c_message=nullptr;
        ErrorState::message(errorMessage);
    }

   ErrorState::~ErrorState() {
    }
    void ErrorState::clear() {
        delete [] c_message;
        c_message = nullptr;
    }
    bool ErrorState::isClear() const {
        return c_message == nullptr;
    }
    void ErrorState::message(const char* str) {
        int length = strlen(str);
        delete [] c_message;
        c_message = new char[length + 1];
        strncpy(c_message, str, length);
        c_message[length + 1] = '\0';
    }
    const char* ErrorState::message() const {
        return c_message;
    }
    std::ostream& operator<<(std::ostream& ostr, const ErrorState& wErrorState) {
        if (wErrorState.message() == nullptr)
            return ostr;
        else {
            ostr << wErrorState.message();
            return ostr;
        }
    }
}