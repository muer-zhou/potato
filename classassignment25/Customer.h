// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Address.h"  // Include the Address structure

namespace CustomerData {
    struct Customer {
        std::string name;
        int age;
        Address address;  // Nested Address structure
    };
}

#endif // CUSTOMER_H

