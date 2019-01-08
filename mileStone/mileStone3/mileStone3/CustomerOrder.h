// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS2_CUSTOMERORDER_H
#define MS2_CUSTOMERORDER_H
#include <string>
#include <iostream>
#include "Item.h"

struct ItemInfo {
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_fillState = false;
    ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem = 0;
    ItemInfo** m_lstItem = nullptr;
    static size_t m_widthField;
    
public:
    CustomerOrder();
    CustomerOrder(std::string&);
    CustomerOrder(const CustomerOrder&);
    CustomerOrder& operator = (const CustomerOrder&) = delete;
    CustomerOrder(CustomerOrder&&) noexcept;
    CustomerOrder& operator = (CustomerOrder&&);
    ~CustomerOrder();
    bool getItemFillState(std::string) const;
    bool getOrderFillState() const;
    void fillItem(Item&, std::ostream&);
    void display(std::ostream&) const;
};

#endif /* CustomerOrder_h */
