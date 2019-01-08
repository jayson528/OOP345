//
//  ProdUtil.cpp
//  WorkShop6
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-02.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#include <sstream>
#include "ProdUtil.h"
#include "iProduct.h"
#include "TaxableProduct.h"
#include "Product.h"

namespace w6 {

    std::ostream& operator << (std::ostream& os_, const iProduct& product_) {
        product_.display(os_);
        return os_;
    };
    
    iProduct* readProduct(std::ifstream& is) {
    
        std::string temp;
        std::getline(is, temp);
        
        if (!temp.empty()) {
            std::istringstream iss(temp);
            std::string tempProductNumber;
            double tempProductPrice;
            char tempTaxableCode;
            iProduct* tempProduct;
            
            iss >> tempProductNumber;
            iss >> tempProductPrice;
            iss >> tempTaxableCode;
            
            if (tempTaxableCode == 'H' || tempTaxableCode == 'P') {
                tempProduct = new TaxableProduct(tempProductNumber, tempProductPrice, tempTaxableCode);
            } else if (tempTaxableCode == 'C' || tempTaxableCode == 'M') {
                throw std::string("Unrecognizable Tax Code!");
            } else {
                tempProduct = new Product(tempProductNumber, tempProductPrice);
            }
            return tempProduct;
        } else {
            return nullptr;
        };
    };
};
