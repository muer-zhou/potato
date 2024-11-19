#include <iostream>
#include "assignment18.h"

using namespace std;
using namespace methods;

int main() {
    int numbers[] = {5, 2, 9, 1, 5, 6};
    size_t size = sizeof(numbers) / sizeof(int);

    cout << "Original array: ";
    for (size_t i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    sortArray(numbers, size);

    cout << "Sorted array: ";
    for (size_t i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
