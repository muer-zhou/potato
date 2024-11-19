#include <iostream>
#include "assignment17.h"

using namespace std;
using namespace methods;

int main() {
    const int numbers[] = {10, 20, 30, 40, 50};
    size_t size = sizeof(numbers) / sizeof(int);

    int target = 30;
    int index = linearSearch(numbers, size, target);

    if (index != -1) {
        cout << "Value found at index: " << index << endl;
    } else {
        cout << "Value not found in the array." << endl;
    }

    return 0;
}
