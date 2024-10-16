#include <iostream>
using namespace std;

shared_ptr<int[]> expand(shared_ptr<int[]> &oldArr, int oldSize, int newSize) { // The int* returns a pointer & expand is a function
    // int *arr means pointer to an array
    shared_ptr<int[]> newArr(new int[newSize]); // This is how you declare a new array in the heap 
    for(int i = 0; i < oldSize; i++) { // it iterates through the old array
        newArr[i] = oldArr[i]; //sets the value of each element in the old array to the new array 
    }
    for (int i = oldSize; i < newSize; i++) { // initalize the rest of the values to zero
        newArr[i] = 0;
    }
    // delete [] oldArr; // deallocates old array
    // oldArr = nullptr; // prevent hanging pointers 
    return newArr; // returns new array 
}

void printArray(shared_ptr<int[]> &arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}