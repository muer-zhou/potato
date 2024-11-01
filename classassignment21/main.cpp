// main.cpp
#include <iostream>
#include <string>
#include "assignment21.h"

using namespace std;
using namespace ArrayOps;

int main() {
    shared_ptr<int[]> arr(new int[1]);
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

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "The sum of the array will be: " << sum << endl;
    printArray(arr, size);
    return 0;
}
