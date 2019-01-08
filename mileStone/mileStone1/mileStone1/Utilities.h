//
//  Utilities.hpp
//  mileStone1
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-12.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#ifndef MS1_UTILITIES_H
#define MS1_UTILITIES_H
#include <iostream>

//namespace ms1 {
    
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
    
//}

#endif /* Utilities_hpp */
