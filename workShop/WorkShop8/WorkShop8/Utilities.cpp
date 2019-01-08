#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"
// Jayson Sherry 141056176 jsherry1@myseneca.ca 2018/11/15
using namespace std;

namespace w8
{
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
    {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using raw pointers
        for (std::size_t i = 0; i < desc.size(); i++) {
            for (std::size_t ii = 0; ii < price.size(); ii++) {
                if (desc[i].code == price[ii].code) {
                    Product* temp = new Product(desc[i].desc,price[ii].price);
                    temp->validate();
                    priceList += temp;
                    delete temp;
                };
            };
        };
        return priceList;
    }
    
    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
    {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using smart pointers
        for (std::size_t i = 0; i < desc.size(); i++) {
            for (std::size_t ii = 0; ii < price.size(); ii++) {
                if (desc[i].code == price[ii].code) {
                    Product* ptr = new Product(desc[i].desc,price[ii].price);
                    std::unique_ptr<Product> temp(ptr);
                    temp->validate();
                    priceList += std::move(temp);
                };
            };
        };
        return priceList;
    }
}


