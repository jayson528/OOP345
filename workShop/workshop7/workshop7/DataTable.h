//
//  DataTable.h
//  workshop7
//
//  Created by Jayson Sherry on 2018-11-07.
//  Copyright © 2018 Jayson Sherry. All rights reserved.
//

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <fstream>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>

namespace w7 {

template <class T>
class DataTable {
    std::vector<T> x, y;
    int fieldWidth, numOfDeci;
    
public:
    DataTable(std::ifstream& fs, int fieldWidth_, int numOfDeci_) : fieldWidth(fieldWidth_), numOfDeci(numOfDeci_) {
        while (fs.good()) {
            std::string temp;
            std::getline(fs, temp);
            if (!temp.empty()) {
                std::istringstream iss(temp);
                T tempX, tempY;
                iss >> tempX;
                iss >> tempY;
                x.push_back(tempX);
                y.push_back(tempY);
            }
        }
    };
    
    T mean() const {
        T mean = std::accumulate(y.begin(), y.end(), 0.0);
        return (mean / y.size());
    };
    
    T sigma() const {
        std::vector<T> temp(y.size());
        std::transform(y.begin(), y.end(), temp.begin(), [&](T element){ return pow((element - mean()),2); });
        T numerator = std::accumulate(temp.begin(), temp.end(), 0.0);
        T denominator = temp.size() - 1;
        return std::sqrt(numerator / denominator);
    };
    
    T median() const {
        T median;
        std::vector<T> tempY = y;
        std::sort(tempY.begin(), tempY.end());
        median = tempY[tempY.size() / 2];
        return median;
    };
    
    void regression(T& slope, T& y_intercept) const {
        T sumOfX = std::accumulate(x.begin(), x.end(), 0.0);
        T sumOfY = std::accumulate(y.begin(), y.end(), 0.0);
        T numerator = x.size() * std::inner_product(x.begin(),x.end(),y.begin(),0.0) - (sumOfX * sumOfY);
        T denominator = (x.size() * std::inner_product(x.begin(),x.end(),x.begin(),0.0)) - pow(sumOfX,2);
        slope = numerator / denominator;
        numerator = sumOfY - slope * sumOfX;
        denominator = x.size();
        y_intercept = numerator / denominator;
    };
    
    void display(std::ostream& os) const {
        os << std::right << std::setw(fieldWidth) << "x" << std::setw(fieldWidth) << "y" << std::endl;
        for (std::size_t i = 0; i < x.size(); i++) {
            os << std::right << std::setw(fieldWidth) << std::setprecision(numOfDeci) << std::fixed << x[i];
            os << std::right << std::setw(fieldWidth) << std::setprecision(numOfDeci) << std::fixed << y[i];
            os << std::endl;
        }
    };
    
    size_t getSize() const {
        return x.size();
    };
    
};

template <class T>
std::ostream& operator << (std::ostream& os, const DataTable<T>& dt) {
    dt.display(os);
    return os;
};
    
};


#endif /* DataTable_h */
