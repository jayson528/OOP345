//
//  ProdUtil.h
//  WorkShop6
//
//  Created by Jayson Sherry 141056176 jsherry1@myseneca.ca on 2018-11-02.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//
#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include "iProduct.h"

namespace w6 {
    
    std::ostream& operator << (std::ostream&, const iProduct&);
    iProduct* readProduct(std::ifstream&);
    
}
#endif
