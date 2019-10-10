// Final Project Milestone 2 - ErrorState Class
// Version 3.3
// ErrorState.h
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
//Name: YC    Date: 2018-03-21
////////////////////////////////////////////////////////////////

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
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
    std::ostream& operator<<(std::ostream& ostr, const ErrorState& wErrorState);
}
#endif