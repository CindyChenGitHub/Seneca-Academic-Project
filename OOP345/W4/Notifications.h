// Workshop 4 - Containers
// Notifications.h
// Yue Chen
// 2018-06-28
#pragma once
#include<fstream>
namespace sict {
    class Message;
    const int M = 10;

    class Notifications {
        Message* message = nullptr;
        int m;
    public:
        Notifications() {}
        Notifications(std::ifstream& inf);  // constructor
        Notifications(Notifications&& _notification); // move constructor
        Notifications& operator=(Notifications&& _notification);  // move assignment operator
        ~Notifications();   // destructor
        void display(std::ostream& os) const;
    };
}
