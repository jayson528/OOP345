//
//  Grades.cpp
//  workshop5
//
// Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-10-09.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#include <iostream>
#include <fstream>
//#include <string>
#include <sstream>
#include "Grades.h"

namespace sict {
    
    Student::Student() {
        studentNumber.clear();
        grade.clear();
    };
    Student::Student(std::string studentNumber_, std::string grade_){
        studentNumber = studentNumber_;
        grade = grade_ + "0";
    };
    std::string Student::getStudentNumber(){
        return studentNumber;
    };
    std::string Student::getStudentGrade(){
        return grade;
    };
    
    Grades::Grades(char* fileName) : students{nullptr}, numOfStudents(0) {
        std::ifstream file(fileName);
        try{
            if (file) {
                std::string line;
                while (!file.eof()) {
                    std::getline(file,line);
                    numOfStudents++;
                }
                students = new Student[numOfStudents];
                file.seekg(0);
                for (std::size_t i = 0; i < numOfStudents; i++){
                    std::string tempStudentNumber;
                    std::string tempGrade;
                    std::string temp;
                    std::getline(file, temp);
                    std::istringstream iss(temp);
                    iss >> tempStudentNumber;
                    iss >> tempGrade;
                    students[i] = Student(tempStudentNumber, tempGrade);
                }
            }else {
                throw ("Could Not Open File");
            };
        } catch(std::string err){
            std::cout << err << std::endl;
        } catch(...){
            std::cout << "failed" << std::endl;
        };
    }
    
    Grades::~Grades(){
        delete [] students;
    };
    
    
};
