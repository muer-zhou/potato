#include <iostream>
#include "assignment19.h"

using namespace std;
using namespace methods;

int main() {
    int x = 10, y = 20;

    cout << "Before swapping: x = " << x << ", y = " << y << endl;

    // Call swap function with pointers to x and y
    swap(&x, &y);

    cout << "After swapping: x = " << x << ", y = " << y << endl;

    return 0;
}
