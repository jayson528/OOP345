//
//  Message.hpp
//  workShop4
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-10-05.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

namespace w4 {
    class Message {
        std::string userName;
        std::string replyTo;
        std::string tweet;
    public:
        Message();
        Message(std::ifstream& in, char c);
        bool empty() const;
        void display(std::ostream&) const;
    };
}

#endif /* Message_hpp */
