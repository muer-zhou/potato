#include <iostream>
#include "assignment22.h"

int main() {
    std::string fullName;
    std::cout << "Enter the full name (first and last name): ";
    std::getline(std::cin, fullName); 

    std::string firstName = extractFirstName(fullName);
    std::string lastName = extractLastName(fullName);

    if (!firstName.empty() && !lastName.empty()) {
        std::cout << "First Name: " << firstName << "\n";
        std::cout << "Last Name: " << lastName << "\n";
    } else {
        std::cout << "Invalid input. Please enter a full name with both first and last names.\n";
    }

    return 0;
}
