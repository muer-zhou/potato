#include <iostream>
using namespace std;

int main() {
    int num;


    cout << "Enter a positive number: ";
    cin >> num;

    if (num <0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    if (num == 0) {
        cout << "Binary representation is: 0" << endl;
        return 0;
    }

    const int SIZE = 32;
    int binary[SIZE];
    int index = 0;

    while (num > 0) {
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }

    cout << "Binary representation is: ";
    for (int i = index -1; i >=0; i--) {
        cout << binary[i];
    }
    cout << endl;
    return 0;
}