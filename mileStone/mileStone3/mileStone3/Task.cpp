// Name: Jayson Sherry
// Seneca Student ID: 141056176
// Seneca email: jsherry1@myseneca.ca
// Date of completion: 2018-11-30
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Task.h"

Task::Task(const std::string& str) :Item(str) {
    m_pNextTask = nullptr;
};

void Task::runProcess(std::ostream& os) {
    if( !m_orders.empty() && !m_orders.back().getOrderFillState() ){
        // This while loop is a bit dangerous because it will always be
        // true if the current Task Item is not found in the order.
        while ( !m_orders.back().getItemFillState( getName() ) ) {
            m_orders.back().fillItem(*this,os);
        };
    };
};

bool Task::moveTask() {
    if ( !m_orders.empty() ) {
        if( m_orders.back().getItemFillState( getName() ) &&  m_pNextTask != nullptr ) {
            *m_pNextTask += std::move(m_orders.back());
            m_orders.pop_back();
            return true;
        };
    };
    return false;
};

void Task::setNextTask(Task& task) {
    m_pNextTask = &task;
};

bool Task::getCompleted(CustomerOrder& custOrd) {
    if ( !m_orders.empty() && m_orders.back().getOrderFillState() ) {
        custOrd = std::move( m_orders.back() );
        m_orders.pop_back();
        return true;
    };
    return false;
};

void Task::validate(std::ostream& os) const {
    os << getName() << " --> " << ((m_pNextTask != nullptr) ? m_pNextTask->getName() : "END OF LINE") << std::endl;
};

Task& Task::operator += (CustomerOrder&& custOrd) {
    m_orders.push_front(std::move( custOrd ) );
    return *this;
};
