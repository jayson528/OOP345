//
//  Utilities.cpp
//  mileStone1
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-12.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#include <iostream>
#include <string>
#include "Utilities.h"

//namespace ms1 {
    char Utilities::m_delimiter = ',';

    Utilities::Utilities() {
        
    };
    
    void Utilities::setFieldWidth(size_t size_) {
        m_widthField = size_;
    };
    
    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    };
    
    const std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more) {
        std::string token = str.substr(next_pos);
        std::size_t delimPos = token.find(m_delimiter);
        token = token.substr(0,delimPos);
        if (token.empty()) {
            throw std::string("No Token was Found");
        };
        next_pos += token.size() + 1;
        next_pos < str.size() - 1 ? more = true : more = false;
        Utilities::m_widthField < token.size() ? Utilities::m_widthField = token.size() : false;
        return token;
    };
    
    void Utilities::setDelimiter(const char delimiter_) {
        m_delimiter = delimiter_;
    };
    
    const char Utilities::getDelimiter() const {
        return m_delimiter;
    };
//}

