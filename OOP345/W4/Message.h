// Workshop 4 - Containers
// Message.h
// Yue Chen
// 2018-06-28
#pragma once
namespace sict {
    class Message {
        char* user = nullptr;
        char* reply = nullptr;
        char* tweet = nullptr;
    public:
        Message() {}
        Message(std::ifstream& in, char c);
        void display(std::ostream& outf) const;
    };
}