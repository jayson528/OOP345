//
//  Notifications.hpp
//  workShop4
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-10-05
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#ifndef W4_NOTIFICATION_H
#define W4_NOTIFICATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Message.h"



class Message;

namespace w4 {
    class Notifications {
        Message* messageArray[10];
        std::size_t numOfMessages;
    public:
        Notifications();
        Notifications(const Notifications& rhs);
        Notifications& operator = (const Notifications&);
        Notifications(Notifications&&);
        Notifications& operator = (Notifications&&);
        ~Notifications();
        void operator += (const Message&);
        void display(std::ostream& os) const;
    };
}

#endif
