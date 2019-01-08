// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS1_ITEM_H
#define MS1_ITEM_H
#include <iostream>
#include <string>

class Item {
    std::string m_name;
    std::string m_description;
    unsigned int m_serialNumber;
    unsigned int m_quantity;
    static size_t m_widthField;
public:
    Item(const std::string&);
    const std::string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(std::ostream&, bool) const;
};

#endif /* Item_h */
