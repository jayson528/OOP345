//
//  Notifications.cpp
//  workShop4
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-10-05
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#include "Notifications.h"

namespace w4 {
    
    // Default Constructor
    Notifications::Notifications() : numOfMessages{0} {
        for(std::size_t i = 0; i < 10; i++){
            messageArray[i] = nullptr;
        };
    };
    
    // Copy Constructor
    Notifications::Notifications(const Notifications& R) {
        numOfMessages = R.numOfMessages;
        if(R.messageArray[0] != nullptr){
            for(std::size_t i = 0; i < numOfMessages; i++){
                messageArray[i] = R.messageArray[i];
            };
        };
    };
    
    // Copy Assignment Operator
    Notifications& Notifications::operator = (const Notifications& R) {
        if (this != &R) {
            numOfMessages = R.numOfMessages;
            for(std::size_t i = 0; i < 10; i++){
                delete messageArray[i];
            };
            for(std::size_t i = 0; i <numOfMessages; i++){
                messageArray[i] = R.messageArray[i];
            };
        };
        return *this;
    };
    
    // Move Constructor
    Notifications::Notifications(Notifications&& R) {
        *this = std::move(R);
    };
    
    // Move Assignment Operator
    Notifications& Notifications::operator = (Notifications&& R) {
        if (this != &R) {
             numOfMessages = R.numOfMessages;
            for(std::size_t i = 0; i < 10; i++){
                delete messageArray[i];
            };
           
            for(std::size_t i = 0; i <numOfMessages; i++){
                messageArray[i] = R.messageArray[i];
            };
            
            for(std::size_t i = 0; i < 10; i++){
                delete R.messageArray[i];
            };
            R.numOfMessages = 0;
        };
        return *this;
    };
    
    // Destructor
    Notifications::~Notifications() {
        for(std::size_t i = 0; i < numOfMessages - 1; i++){
            delete messageArray[i];
        };
    };
    
    // OverLoaded += operator to add new message to array
    void Notifications::operator += (const Message& msg){
        //messageArray[numOfMessages] = new Message;
        messageArray[numOfMessages] = new Message(msg);
        numOfMessages++;
    };
    
    // Display function
    void Notifications::display(std::ostream& os) const {
        for (std::size_t i = 0; i < numOfMessages; i++) {
            messageArray[i]->display(os);
            os << std::endl;
        };
    };
};
