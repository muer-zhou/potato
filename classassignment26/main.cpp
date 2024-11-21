#include <iostream>
#include "assignment26.h"

using namespace std;
using namespace assignment26;

int main() {
    // Create two Point objects
    Point p1{3.5, 4.2};
    Point p2{3.5, 4.2};
    Point p3{1.0, 2.0};

    // Test the equality operator (==)
    if (p1 == p2) {
        cout << "Point p1 is equal to Point p2" << endl;
    } else {
        cout << "Point p1 is not equal to Point p2" << endl;
    }

    if (p1 == p3) {
        cout << "Point p1 is equal to Point p3" << endl;
    } else {
        cout << "Point p1 is not equal to Point p3" << endl;
    }

    // Test the stream insertion operator (<<)
    cout << "Point p1: " << p1 << endl;
    cout << "Point p2: " << p2 << endl;
    cout << "Point p3: " << p3 << endl;

    return 0;
}
