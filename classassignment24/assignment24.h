#ifndef ASSIGNMENT24_H
#define ASSIGNMENT24_H

#include <string>

namespace assignment24 {
    struct Customer {
        int id;
        std::string name;
        std::string email;

        void printDetails() const;
    };
}

#endif 
