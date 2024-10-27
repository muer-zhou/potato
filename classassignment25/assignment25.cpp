#include <iostream>
#include <string>
using namespace std;

// Define the Address structure
struct Address {
    string street;
    string city;
    int zipCode;
};

// Define the Customer structure, with an Address nested inside
struct Customer {
    string name;
    int age;
    Address address; // Nested Address structure
};

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
