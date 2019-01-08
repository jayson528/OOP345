//
//  TaxableProduct.h
//  WorkShop6
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-02.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H

#include <array>
#include "Product.h"

namespace w6 {

    class TaxableProduct : public Product {
        
        std::array<double, 2> taxes {{1.13,1.08}};
        //double taxes[2] = {1.13, 1.08};
        char taxableCode;
        
    public:
        TaxableProduct(std::string , double, char);
        double getPrice() const;
        void display(std::ostream&) const;
    };
}

#endif /* TaxableProduct_hpp */
