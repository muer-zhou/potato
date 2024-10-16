#include <iostream>
using namespace std;

int* expand(int *oldArr, int oldSize, int newSize) { // The int* returns a pointer & expand is a function
    // int *arr means pointer to an array
    int *newArr = new int[newSize]; // This is how you declare a new array in the heap 
    for(int i = 0; i < oldSize; i++) { // it iterates through the old array
        newArr[i] = oldArr[i]; //sets the value of each element in the old array to the new array 
    }
    for (int i = oldSize; i < newSize; i++) { // initalize the rest of the values to zero
        newArr[i] = 0;
    }
    delete [] oldArr; // deallocates old array
    oldArr = nullptr; // prevent hanging pointers 
    return newArr; // returns new array 
} // entire function expands new array 
// function to expand our dynamically allocated array 
// a nornal array stored in the stack must be known at compile time (this is the reason why we are using dynamically allocated arrays )

// a pointer is a memory address

void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}