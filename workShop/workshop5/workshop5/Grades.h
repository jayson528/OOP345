//
//  Grades.hpp
//  workshop5
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-10-09.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

//#include <stdio.h>
//#include <fstream>
//#include <string>
#include <iomanip>

#ifndef SICT_GRADES_H
#define SICT_GRADES_H

namespace sict {
    
    class Student {
        std::string studentNumber;
        std::string grade;
    public:
        Student();
        Student(std::string, std::string);
        std::string getStudentNumber();
        std::string getStudentGrade();
    };
    
    class Grades {
        Student* students;
        std::size_t numOfStudents;
    public:
        Grades(char*);
        ~Grades();
        template<typename F>
        void displayGrades(std::ostream& os, F func) const {
            for (std::size_t i = 0; i < numOfStudents; i++) {
                os << "    " << students[i].getStudentNumber() << " " <<  students[i].getStudentGrade() << " ";
                os << func(std::stof(students[i].getStudentGrade())) << std::endl;
            };
        };
    };
};
#endif /* Grades_hpp */
