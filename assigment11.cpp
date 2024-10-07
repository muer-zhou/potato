#include <iostream>
using namespace std;

int main() {
    int value1, value2, largerValue;

    cout << "Enter the first value: ";
    cin >> value1;

    cout << "Enter the second value: ";
    cin >> value2;

    if (value1 > value2) {
        largerValue = value1;
    } else {
        largerValue = value2;
    }

    cout << "The larger value is: " << largerValue << endl;

    return 0;
}