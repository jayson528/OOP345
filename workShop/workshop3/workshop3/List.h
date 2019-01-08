//
//  List.h
//  WorkShop3
//
//  Created by Jayson Sherry on 2018-09-25.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#ifndef List_h
#define List_h

template<typename T, size_t N>
class List {
    T array[N];
    size_t numOfElements = 0;
public:
    List(){
        array = {};
    }
    size_t size() const {
        return numOfElements;
    }
    const T& operator [] (int index_) const {
        return array[index_];
    }
    void operator += (const T& item_) {
        if (numOfElements < N){
            array[numOfElements] = item_;
            numOfElements++;
        }
    }
};

#endif /* List_h */
