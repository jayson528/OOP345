#ifndef W8_UTILITIES_H
#define W8_UTILITIES_H
#include "List.h"
#include "Element.h"
// Jayson Sherry 141056176 jsherry1@myseneca.ca 2018/11/15
namespace w8 {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif
