//
//  Product.h
//  WorkShop6
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-02.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include "iProduct.h"

namespace w6 {
    
    class Product : public iProduct {
    protected:
        std::string productNumber;
        double productCost;
    
    public:
        Product(std::string, double);
        double getPrice() const;
        void display(std::ostream&) const;
    };
    
}

#endif /* Product_hpp */
