#include <iostream>
#include <memory>

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
} // entire function expands new array 
// function to expand our dynamically allocated array 
// a nornal array stored in the stack must be known at compile time (this is the reason why we are using dynamically allocated arrays )

// a pointer is a memory address

void printArray(shared_ptr<int[]> &arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    shared_ptr<int[]> arr(new int[1]);
    // int *arr = new int[1]; // creating a new interger array with size one in the heap dynamically allocated 
    int size = 1;
    for (int i = 0; true; i++) { // run indefinitely
        cout << "Enter a number, or type 's' to stop: ";
        string userInput = ""; // makes it a string 
        cin >> userInput;
        if (userInput == "s") {
            break;
        }
        int num = stoi(userInput); 
        if (i >= size) { // to check if the array is at max capacity
            arr = expand(arr, size, 2*size); // it doubles the size of the array
            size *= 2;
            arr[i] = num;
        }
        else {
            arr[i] = num;
        }

    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "The sum of the array will be:" << sum << endl;
    printArray(arr, size);
    return 0;
}
