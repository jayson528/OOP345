// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS3_LINEMANAGER_H
#define MS3_LINEMANAGER_H
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include "CustomerOrder.h"
#include "Task.h"

class LineManager {
    std::vector<Task*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    unsigned int m_cntCustomerOrder;
    
public:
    LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
    bool run(std::ostream&);
    void displayCompleted(std::ostream&) const;
    void validateTasks() const;
};

#endif /* LinerManager_h */
