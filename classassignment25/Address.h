// Address.h
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

namespace CustomerData {
    struct Address {
        std::string street;
        std::string city;
        int zipCode;
    };
}

#endif // ADDRESS_H
