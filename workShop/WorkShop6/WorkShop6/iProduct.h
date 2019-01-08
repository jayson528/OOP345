//
//  iProduct.h
//  WorkShop6
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-02.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H

#include <iostream>
#include <fstream>

namespace w6 {
    
    class iProduct {
        
    public:
        virtual double getPrice() const = 0;
        virtual void display(std::ostream&) const = 0;
    };
}

#endif /* iProduct_h */
