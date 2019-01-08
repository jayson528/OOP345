// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS1_UTILITIES_H
#define MS1_UTILITIES_H
#include <iostream>
#include <string>
    
class Utilities {
    size_t m_widthField = 1;
    static char m_delimiter;
public:
    Utilities();
    void setFieldWidth(size_t);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string&, size_t&, bool&);
    static void setDelimiter(const char);
    const char getDelimiter() const;
};

#endif /* Utilities_h */
