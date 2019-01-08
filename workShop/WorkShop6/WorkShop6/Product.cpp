//
//  Product.cpp
//  WorkShop6
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-02.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#include <iomanip>
#include "Product.h"

namespace w6 {

Product::Product(std::string productNumber_, double productCost_) : productCost{productCost_} {
    productNumber = productNumber_;
};

double Product::getPrice() const {
    return productCost;
}

void Product::display(std::ostream & os) const {
    os << std::setw(16) << productNumber << std::setw(16) << std::fixed << std::setprecision(2) << productCost << std::endl;
}
}
