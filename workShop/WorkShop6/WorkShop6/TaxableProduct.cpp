//
//  TaxableProduct.cpp
//  WorkShop6
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-02.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#include <iomanip>
#include "TaxableProduct.h"

namespace w6 {
    
    TaxableProduct::TaxableProduct(std::string productNumber_, double productCost_, char taxableCode_) : Product(productNumber_, productCost_), taxableCode{taxableCode_}{
    
    };

    double TaxableProduct::getPrice() const {
        return productCost * (taxableCode == 'H' ? taxes[0] : taxes[1]);
    }

    void TaxableProduct::display(std::ostream & os) const {
        os << std::setw(16) << productNumber;
        os << std::setw(16) << std::fixed << std::setprecision(2) << productCost;
        if (taxableCode == 'H'){
            os << " HST" << std::endl;
        } else {
            os << " PST" << std::endl;
        };
    }
};
