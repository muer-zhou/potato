#include "assignment23.h"
#include <cctype> 

bool isValidCustomerNumber(const std::string& customerNumber) {
    if (customerNumber.length() != 6) {
        return false;
    }

    if (!std::isalpha(customerNumber[0]) || !std::isalpha(customerNumber[1])) {
        return false;
    }

    for (size_t i = 2; i < 6; ++i) {
        if (!std::isdigit(customerNumber[i])) {
            return false;
        }
    }

    return true; 
}
