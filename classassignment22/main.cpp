#include <iostream>
#include "assignment22.h"

using namespace std;
using namespace methods;

int main() {
    string fullName;
    
    cout << "Enter the full name: ";
    getline(cin, fullName); // Get the full name from the user

    auto [firstName, lastName] = extractFirstAndLastName(fullName);

    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;

    return 0;
}
