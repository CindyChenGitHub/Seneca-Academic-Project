// Workshop 4 - Containers
// Message.cpp
// Yue Chen
// 2018-06-28
#include <iostream>
#include <fstream>
#include <string>
#include <new>
#include "Message.h"
using namespace sict;
Message::Message(std::ifstream& in, char c) {
    if (in) {
        std::string tempStr;
        if (getline(in, tempStr)) {
            int c1 = 0;
            int c2 = 0;
            int length = tempStr.length();
            if (length) {
                c1 = tempStr.find(c);
                if (c1 > 0) {
                    user = new char[c1 + 1];
                    for (int i = 0; i < c1; i++)
                        user[i] = tempStr[i];
                    user[c1] = '\0';
                    int findReply = tempStr.find('@');
                    if (findReply > 0) {
                        c2 = tempStr.find(c, c1 + 1);
                        reply = new char[c2 - findReply];
                        for (int j = (findReply + 1); j < c2; j++)
                            reply[j - findReply - 1] = tempStr[j];
                        reply[c2 - findReply - 1] = '\0';
                    }
                    else
                        c2 = c1;
                    tweet = new char[length - c2];
                    for (int k = c2 + 1; k < length; k++)
                        tweet[k - c2 - 1] = tempStr[k];
                    tweet[length - c2 - 1] = '\0';
                }
                else {
                    user = new char[length + 1];
                    for (int i = 0; i < length; i++)
                        user[i] = tempStr[i];
                    user[length] = '\0';
                }
            }
        }
    }
}

void Message::display(std::ostream& outf) const {
    if (tweet) {
        outf << "Message" << std::endl;
        outf << " User  : " << user << std::endl;
        if (reply)
            outf << " Reply : " << reply << std::endl;
        outf << " Tweet : " << tweet << std::endl << std::endl;
    }
}