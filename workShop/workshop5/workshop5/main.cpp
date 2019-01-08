// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

auto letter = [](float grade) {
    if (grade >= 90) return convert(Letter::Ap);
    else if (grade >= 80) return convert(Letter::A);
    else if (grade >= 75) return convert(Letter::Bp);
    else if (grade >= 70) return convert(Letter::B);
    else if (grade >= 65) return convert(Letter::Cp);
    else if (grade >= 60) return convert(Letter::C);
    else if (grade >= 55) return convert(Letter::Dp);
    else if (grade >= 50) return convert(Letter::D);
    else return  convert(Letter::F);
};

int main(int argc, char* argv[]) {
    
    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;
    
    if (argc == 1) {
        std::cerr << "\n*** Insufficient number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << "\n*** Too many arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 2;
    }
    else {
        try {
            sict::Grades grades(argv[1]);
            //TODO: Update the main functions as per the specifications here
            grades.displayGrades(std::cout, letter);
        }
        catch (std::string msg) {
            std::cerr << argv[0] << ": Failed to open file "
            << argv[1] << "\n";
            return 2;
        }
    }
    return 0;
}
