// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <algorithm>
#include "Utilities.h"

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
    if (token[token.size() - 1] == 13 || token[token.size() - 1] == 10) {
        token.pop_back();
    };
    return token;
};
    
void Utilities::setDelimiter(const char delimiter_) {
    m_delimiter = delimiter_;
};
    
const char Utilities::getDelimiter() const {
    return m_delimiter;
};
