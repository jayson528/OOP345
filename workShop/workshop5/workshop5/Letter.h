//
//  Letter.h
//  workshop5
//
// Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-10-09.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

//#include <string>
//#include <iostream>

#ifndef SICT_LETTER_H
#define SICT_LETTER_H

namespace sict {

    enum Letter {Ap, A, Bp, B, Cp, C, Dp, D, F};
    
    template <typename T>
    std::string convert(const T& ltr){
        switch (ltr) {
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
            default:
                return " ";
                break;
                
        }
    };
}
#endif /* Letter_h */

