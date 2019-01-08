// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iomanip>
#include "Item.h"
#include "Utilities.h"

std::size_t Item::m_widthField = 0;

Item::Item(const std::string& str) {
    if (!str.empty()) {
        Utilities util;
        std::size_t pos = 0;
        bool more = true;
        try {
            if (more) { m_name = util.extractToken(str, pos, more); };
            if (more) { m_serialNumber = std::stoi(util.extractToken(str, pos, more)); };
            if (more) { m_quantity = std::stoi(util.extractToken(str, pos, more)); };
            Item::m_widthField < util.getFieldWidth() ? m_widthField = util.getFieldWidth() : false;
            if (more) { m_description = util.extractToken(str, pos, more); };
        } catch (std::string error) {
            std::cout << error << std::endl;
        }
    };
};
    
const std::string& Item::getName() const {
    return m_name;
};
    
const unsigned int Item::getSerialNumber() {
    return m_serialNumber++;
};
    
const unsigned int Item::getQuantity() {
    return m_quantity;
};
    
void Item::updateQuantity() {
    if (m_quantity > 0) {
        m_quantity--;
    };
};
    
void Item::display(std::ostream& os, bool full) const {
    if (full) {
        os << std::left << std::setw((int)m_widthField) << m_name;
        os << " [" << std::right << std::setfill('0') << std::setw(6) << m_serialNumber << "]" << std::setfill(' ');
        os << std::left << " Quantity: " << std::setw((int)m_widthField) << m_quantity;
        os << " Description: " << std::setw((int)m_widthField) << m_description << std::endl;
    } else {
        os << std::left << std::setw((int)m_widthField) << m_name;
        os << " [" << std::right << std::setfill('0') << std::setw(6) << m_serialNumber << "]" << std::setfill(' ') << std::endl;
    };
};
