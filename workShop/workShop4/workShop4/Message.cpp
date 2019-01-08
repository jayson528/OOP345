//
//  Message.cpp
//  workShop4
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-10-05.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//
#include <string>
#include <iostream>
#include <sstream>
#include "Message.h"

namespace w4{

    // Default Constructor
    Message::Message() : userName {'\0'} , replyTo {'\0'} , tweet {'\0'} {
        
    };

    // Constructor to save message
    Message::Message(std::ifstream& in, char c){
        if (in){
            std::string temp;
            getline(in, temp, c);
            std::istringstream iss(temp);
            iss >> userName;
            iss >> replyTo;
            if(replyTo[0] != '@'){
                replyTo.clear();
                iss.seekg((int)userName.size() + 1);
                getline(iss, tweet);
            }else{
                replyTo.erase(0,1);
                getline(iss, tweet);
                tweet.erase(0,1);
            };
            if(tweet.empty()){
                userName.clear();
                replyTo.clear();
                tweet.clear();
            };
            iss.clear();
        };
    };

    // Quary function to see if obj is in an empty state
    bool Message::empty() const{
        return (userName.empty() || tweet.empty());
    };

    // Function to display message
    void Message::display(std::ostream& os) const {
        os << "Message" << std::endl;
        os << " User  : " << userName << std::endl;
        if (!replyTo.empty()) {
            os << " Reply : " << replyTo << std::endl;
        };
        os << " Tweet : " << tweet << std::endl;
    };
};
