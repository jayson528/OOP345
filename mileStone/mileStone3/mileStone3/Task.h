// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef MS3_TASK_H
#define MS3_TASK_H
#include <deque>
#include <string>
#include <iostream>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item {
    std::deque<CustomerOrder> m_orders;
    Task* m_pNextTask;
public:
    Task(const std::string&);
    Task(const Task&) = delete;
    Task& operator = (const Task&) = delete;
    Task(Task&&) = delete;
    Task& operator = (Task&&) = delete;
    void runProcess(std::ostream&);
    bool moveTask();
    void setNextTask(Task&);
    bool getCompleted(CustomerOrder&);
    void validate(std::ostream&) const;
    Task& operator += (CustomerOrder&&);
};

#endif /* Task_h */
