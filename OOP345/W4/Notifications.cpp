// Workshop 4 - Containers
// Notifications.cpp
// Yue Chen
// 2018-06-28
#include "Notifications.h"
#include "Message.h"

using namespace sict;
Notifications::Notifications(std::ifstream& inf) {
    message = new Message[M];
    m = 0;
    for (int i = 0; i < M && !inf.eof(); i++) {
        message[i] = Message(inf, ' ');
        m++;
    }
}

Notifications::Notifications(Notifications&& _notification) {
    *this = std::move(_notification);
}

Notifications& Notifications::operator=(Notifications&& _notification) {
    if (this != &_notification) {
        message = std::move(_notification.message);
        m = _notification.m;
        _notification.message = nullptr;
        _notification.m = 0;
        return *this;
    }
}

Notifications::~Notifications() {}

void Notifications::display(std::ostream& os) const {
    for (int i = 0; i < M && i < m; i++) {
        message[i].display(os);
    }
}