#include <iostream>
#include <string>
using namespace std;

// Constructor
struct Customer {
    int id;
    string name;
    string email;
};

int main() {
    // Creating an instance of the Customer 
    Customer customer; 

    // Ask for name, email and ID
    cout << "Enter customer name: ";
    getline(cin, customer.name);

    cout << "Enter customer email: ";
    getline(cin, customer.email);

    cout << "Enter customer ID: ";
    cin >> customer.id;

    // Print the result
    cout << "\nCustomer Details: " << endl;
    cout << "Name: " << customer.name << endl;
    cout << "Email: " << customer.email << endl;
    cout << "ID: " << customer.id << endl;

    return 0;
}