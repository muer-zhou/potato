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



