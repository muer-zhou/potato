#include "assignment24.h"
#include <iostream>

namespace assignment24 {
    void Customer::printDetails() const {
        std::cout << "\nCustomer Details: " << std::endl;
        std::cout << "ID: " << id << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Email: " << email << std::endl;
    }
}