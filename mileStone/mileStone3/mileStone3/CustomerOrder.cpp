// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <vector>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {
     m_name.clear();
     m_product.clear();
     m_cntItem = 0;
     m_lstItem = nullptr;
};

CustomerOrder::CustomerOrder(std::string& str) {
    if (!str.empty()) {
        Utilities util;
        std::size_t pos = 0;
        bool more = true;
        std::vector<ItemInfo*> tempVector;
        try {
            if (more) { m_name = util.extractToken(str, pos, more); };
            if (more) { m_product = util.extractToken(str, pos, more); };
            while (more) {
                std::string tempItem = util.extractToken(str, pos, more);
                ItemInfo* tempInfoItem = new ItemInfo(tempItem);
                tempVector.push_back(tempInfoItem);
            }
            
            m_cntItem = (int)tempVector.size();
            m_lstItem = new ItemInfo*[m_cntItem];
            for (std::size_t i = 0; i < m_cntItem; i++) {
                m_lstItem[i] = tempVector[i];
            }
            CustomerOrder::m_widthField < util.getFieldWidth() ? CustomerOrder::m_widthField = util.getFieldWidth() : false;
        } catch (std::string error) {
            std::cout << error << std::endl;
        }
    };
};

CustomerOrder::CustomerOrder(const CustomerOrder& cusOrd) {
    throw std::string("Copy Operations Are NOT Allowed");
};

CustomerOrder::CustomerOrder(CustomerOrder&& cusOrd) noexcept {
    *this = std::move(cusOrd);
};

CustomerOrder& CustomerOrder::operator = (CustomerOrder&& cusOrd) {
    if (this != &cusOrd) {
        if(m_lstItem != nullptr){
            for(std::size_t i = 0; i < m_cntItem ; i++) {
                delete m_lstItem[i];
            };
            delete [] m_lstItem;
        };
        m_name = cusOrd.m_name;
        m_product = cusOrd.m_product;
        m_cntItem = cusOrd.m_cntItem;
        m_lstItem = cusOrd.m_lstItem;
        cusOrd.m_cntItem = 0;
        cusOrd.m_lstItem = nullptr;
    };
    return *this;
};

CustomerOrder::~CustomerOrder(){
    for(std::size_t i = 0; i < m_cntItem; i++) {
        delete m_lstItem[i];
    };
    delete [] m_lstItem;
};

bool CustomerOrder::getItemFillState(std::string str) const {
    bool result = true;
    for(std::size_t i = 0; i < m_cntItem; i++) {
        (str == m_lstItem[i]->m_itemName) ? result = m_lstItem[i]->m_fillState : false;
    };
    return result;
};

bool CustomerOrder::getOrderFillState() const {
    bool result = false;
    for(std::size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_fillState) {
            result = true;
        } else {
            result = false;
            break;
        };
    };
    return result;
};

void CustomerOrder::fillItem(Item& item, std::ostream& os) {
    for (std::size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == item.getName()) {
            if (item.getQuantity()) {
                item.updateQuantity();
                m_lstItem[i] = new ItemInfo(item.getName());
                m_lstItem[i]->m_serialNumber = item.getSerialNumber();
                m_lstItem[i]->m_fillState = true;
                os << "Filled ";
            } else {
                os << "Unable to fill ";
            };
            os << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
        };
    };
};

void CustomerOrder::display(std::ostream& os) const {
    os << m_name << " - " << m_product << std::endl;
    for (std::size_t i = 0; i < m_cntItem; i++) {
        os <<  "[" << std::right << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
        os << std::left << std::setfill(' ') << std::setw((int)CustomerOrder::m_widthField) << m_lstItem[i]->m_itemName << " - ";
        os << ((m_lstItem[i]->m_fillState) ? "FILLED" : "MISSING") << std::endl;
    };
};
