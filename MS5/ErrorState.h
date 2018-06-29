// Final Project Milestone 5
// Version 1.0
// ErrorState.h
// -----------------------------------------------------------
//Student:  YC    Date: 2018-04-15
////////////////////////////////////////////////////////////////
#ifndef AMA_ERRORSTATE_H_
#define AMA_ERRORSTATE_H_
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'

#include <iostream>
namespace AMA {
    // set ErrorState class： manages the error state of client code and encapsulates the last error message. 
    //
    class ErrorState {
        char* c_message;
    public:
        ErrorState();           // Default constructor, set to safe empty.
        ErrorState(const char* errorMessage);       // Overload constructor, receive a massage(string) pointer.
        ErrorState(const ErrorState& em) = delete;  // Overload constructor, receive a massage(string) reference.
        ErrorState& operator=(const ErrorState& em) = delete;   // operator copy function.
        virtual ~ErrorState();          // Destructor function
        void clear();           // clear massage, and set to safe empty state.
        bool isClear() const;   // return true when current object is in safe empty state.
        void message(const char* str);  // set message by a string pointer
        const char* message() const;    // get message by pointer
    };
    std::ostream& operator<<(std::ostream& ostr, const ErrorState& wErrorState); //helper operator function to display the error message.
}
#endif
