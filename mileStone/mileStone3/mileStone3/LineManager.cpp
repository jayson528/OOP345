// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include "LineManager.h"
#include "Utilities.h"
#include "Task.h"

LineManager::LineManager(const std::string& str, std::vector<Task*>& task, std::vector<CustomerOrder>& custOrd) : m_cntCustomerOrder{0}{
    std::ifstream file(str);
    while(!file.eof()) {
        std::string item1, item2, line;
        std::getline(file, line);
        Utilities util;
        std::size_t pos = 0;
        bool more = true;
        if (more) { item1 = util.extractToken(line, pos, more); };
        if (more) { item2 = util.extractToken(line, pos, more); };
        for(std::size_t i = 0; i < task.size(); i++) {
            if( item1 == task[i]->getName() ) {
                if(!item2.empty()) {
                    for(std::size_t j = 0; j < task.size(); j++) {
                        if(item2 == task[j]->getName() ) {
                            task[i]->setNextTask(*task[j]);
                        };
                    };
                };
            };
        };
    };
    for(std::size_t i = 0; i < custOrd.size(); i++) {
        ToBeFilled.push_front( std::move( custOrd[i] ) );
        m_cntCustomerOrder++;
    };
    for(std::size_t i = 0; i < task.size(); i++) {
        AssemblyLine.push_back( task[i] );
    };
};

bool LineManager::run(std::ostream& os) {
    if (!ToBeFilled.empty()) {
        for(std::size_t i = 0; i < AssemblyLine.size(); i++) {
            if(AssemblyLine[i]->getName() == "Power Supply") {
                *AssemblyLine[i] += std::move( ToBeFilled.back() );
                ToBeFilled.pop_back();
            };
        };
    };
    for(std::size_t i = 0; i < AssemblyLine.size(); i++) {
        AssemblyLine[i]->runProcess(os);
    };
    for (size_t i = 0; i < AssemblyLine.size(); ++i) {
        AssemblyLine[i]->moveTask();
    };
    for(std::size_t i = 0; i < AssemblyLine.size(); i++) {
        CustomerOrder temp;
        if (AssemblyLine[i]->getCompleted(temp))
            Completed.push_back( std::move(temp) );
    };
    return (Completed.size() < m_cntCustomerOrder) ? false : true;
};

void LineManager::displayCompleted(std::ostream& os) const {
    if(!Completed.empty()) {
        for(std::size_t i = 0; i < Completed.size(); i++) {
            Completed[i].display(os);
        };
    };
};

void LineManager::validateTasks() const {
    for(std::size_t i = 0; i < AssemblyLine.size(); i++) {
        AssemblyLine[i]->validate(std::cout);
    };
};
