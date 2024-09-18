#include <iostream>
using namespace std;

int main() {
    int number;
    unsigned long long factorial = 1;

    cout << "Enter a positive number: ";
    cin >> number;

    if (number < 0) {
        cout << "Please enter a positive number: " << endl;
    } else {
        for (int i = 1; i<= number; ++i) {
            factorial *= i;
        }
        cout << "The factorial of " << number << " is: " << factorial << endl;

    }
    return 0;
}