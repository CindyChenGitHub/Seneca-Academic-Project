// Final Project Milestone 5
// Version 1.0
// ErrorState.cpp
// -----------------------------------------------------------
//Student:  Yue Chen    Date: 2018-04-15
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
    // Default constructor, set to safe empty.
    //
    ErrorState::ErrorState() {
        c_message = nullptr;
    }

    // Overload constructor, receive a massage(string) pointer.
    //
    ErrorState::ErrorState(const char* errorMessage) {
        c_message = nullptr;
        message(errorMessage);
    }

    // Destructor function
    //
    ErrorState::~ErrorState() {
    }

    // clear massage, and set to safe empty state.
    //
    void ErrorState::clear() {
        //delete[] c_message;   // could leat to debug error
        c_message = nullptr;
    }

    // return true when current object is in safe empty state.
    //
    bool ErrorState::isClear() const {
        return c_message == nullptr;
    }

    // set message by a string pointer
    //
    void ErrorState::message(const char* str) {
        int length = strlen(str);
        // delete[] c_message;      // could leat to debug error
        c_message = new char[length ];      // allocate a dynamic memory to store message(string).
        strncpy(c_message, str, length);
        c_message[length ] = '\0';
    }

    // get message pointer
    //
    const char* ErrorState::message() const {
        return c_message;
    }

    //helper operator function to display the error message.
    //
    std::ostream& operator<<(std::ostream& ostr, const ErrorState& wErrorState) {
        if (wErrorState.message() == nullptr)   // if the errorstate message is empty, do noting
            return ostr;
        else {
            ostr << wErrorState.message();  // if the errorstate message is not empty, display the message.
            return ostr;
        }
    }
}