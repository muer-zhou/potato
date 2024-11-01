// main.cpp
#include <iostream>
#include <string>
#include "assignment20.h"

using namespace std;
using namespace ArrayOps;

int main() {
    int *arr = new int[1];
    int size = 1;
    for (int i = 0; true; i++) {
        cout << "Enter a number, or type 's' to stop: ";
        string userInput;
        cin >> userInput;
        if (userInput == "s") {
            break;
        }
        int num = stoi(userInput);
        if (i >= size) {
            arr = expand(arr, size, 2 * size);
            size *= 2;
            arr[i] = num;
        } else {
            arr[i] = num;
        }
    }
    printArray(arr, size);
    delete[] arr;  // Deallocate final array to prevent memory leaks
    return 0;
}
