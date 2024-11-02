// main.cpp
#include <iostream>
#include "assignment26.h"

using namespace std;

int main() {
    Point p1 = {3, 4};
    Point p2 = {3, 4};
    Point p3 = {5, 6};

    // Test equality operator
    if (p1 == p2) {
        cout << "p1 is equal to p2" << endl;
    } else {
        cout << "p1 is not equal to p2" << endl;
    }

    if (p1 == p3) {
        cout << "p1 is equal to p3" << endl;
    } else {
        cout << "p1 is not equal to p3" << endl;
    }

    // Test stream insertion operator
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;

    return 0;
}
