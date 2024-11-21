#include <iostream>
#include "assignment24.h"

using namespace std;
using namespace assignment24;

int main() {
    // Create a Customer object
    Customer customer;

    // Ask for customer details
    cout << "Enter customer ID: ";
    cin >> customer.id;
    cin.ignore(); // Clear the input buffer

    cout << "Enter customer name: ";
    getline(cin, customer.name);

    cout << "Enter customer email: ";
    getline(cin, customer.email);

    // Print the result using the printDetails function
    customer.printDetails();

    return 0;
}
