// Workshop 5 - Lambda Expression
// Letter.h
// Yue Chen
// 2018-06-28
#pragma once
namespace sict {
    enum Letter { Ap, A, Bp, B, Cp, C, Dp, D, F };   
    std::string getLetter(const Letter _letter) {
        switch (_letter) {
        case Ap:
            return "A+";
            break;
        case A:
            return "A";
            break;
        case Bp:
            return "B+";
            break;
        case B:
            return "B";
            break;
        case Cp:
            return "C+";
            break;
        case C:
            return "C";
            break;
        case Dp:
            return "D+";
            break;
        case D:
            return "D";
            break;
        case F:
            return "F";
            break;
        }
    }
}