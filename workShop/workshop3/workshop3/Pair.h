//
//  Pair.h
//  WorkShop3
//
//  Created by Jayson Sherry on 2018-09-25.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#ifndef Pair_h
#define Pair_h

template<typename A, typename B>
class Pair {
    A key;
    B value;
public:
    Pair(){
        
    }
    Pair(const A& key_, const B& value_) {
        key = key_;
        value = value_;
    }
    const A& getKey() const {
        return key;
    }
    const B& getValue() const {
        return value;
    }
};

#endif /* Pair_h */
