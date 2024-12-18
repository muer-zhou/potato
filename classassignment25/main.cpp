// main.cpp
#include <iostream>
#include "Customer.h"

using namespace std;
using namespace CustomerData;

int main() {
    // Initialize a Customer object with nested Address data
    Customer customer = {
        "John Doe",               // name
        30,                       // age
        {"123 Main St", "Berkeley", 94704} // Address: street, city, zipCode
    };

    // Display customer information
    cout << "Customer Information:" << endl;
    cout << "Name: " << customer.name << endl;
    cout << "Age: " << customer.age << endl;
    cout << "Address: " << customer.address.street << ", "
         << customer.address.city << ", " << customer.address.zipCode << endl;

    return 0;
}
