// Final Project Milestone 2 - ErrorState Class
// Version 3.3
// ErrorState.h
// Date	2018-03-03
// Author	Chris Szalwinski, Fardad Soleimanloo
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
/////////////////////////////////////////////////////////////////
//Student:
//--------------------------------
//Name: Yue Chen    Date: 2018-03-21
////////////////////////////////////////////////////////////////

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'
namespace AMA {
    class ErrorState {
        char* c_message;
    public:
        ErrorState();
        ErrorState(const char* errorMessage);
        ErrorState(const ErrorState& em) = delete;
        ErrorState& operator=(const ErrorState& em) = delete;
        virtual ~ErrorState();
        void clear();
        bool isClear() const;
        void message(const char* str);
        const char* message() const;
    };
    std::ostream& operator<<(std::ostream& ostr, const ErrorState& wErrorState) ;
}
#endif