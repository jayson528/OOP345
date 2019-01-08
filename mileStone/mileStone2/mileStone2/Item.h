//
//  Item.hpp
//  mileStone1
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-12.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//
// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-12
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS1_ITEM_H
#define MS1_ITEM_H
#include <iostream>

//namespace ms1 {
    
    class Item {
        std::string m_name;
        std::string m_description;
        unsigned int m_serialNumber;
        unsigned int m_quantity;
        static size_t m_widthField;
    public:
        Item(const std::string);
        const std::string& getName() const;
        const unsigned int getSerialNumber();
        const unsigned int getQuantity();
        void updateQuantity();
        void display(std::ostream&, bool) const;
    };
    
//}

#endif /* Item_hpp */
