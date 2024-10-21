# Assignment 20 - Dynamic Array Expansion with Manual Memory Management

## Description
This program demonstrates dynamic memory allocation for an integer array using raw pointers in C++. The program accepts user input, dynamically expands the array size when needed, and prints the array contents along with the sum of all elements. 

The program includes:
- **Dynamic memory allocation** with raw pointers (`int*`).
- **Array expansion** when the array reaches capacity.
- **Summation** of the array elements.
- **Manual memory deallocation** to avoid memory leaks.

## Files
- `assignment20.cpp`: The main source code file, which implements dynamic array expansion and printing the array’s contents.
- `assignment20.h`: Header file that declares the functions used for array expansion and printing.
- `README.md`: This file, providing a description of the project.

## How the Program Works
1. **Memory Allocation**: 
    - The array is dynamically allocated in the heap using `int*`, and starts with a size of 1.
    
2. **Array Expansion**:
    - The array expands when the user enters more elements than the current size can accommodate.
    - The `expand()` function creates a new larger array, copies the old elements, and initializes new elements to zero.

3. **User Input**:
    - The program asks the user to enter numbers.
    - The array expands automatically when more space is needed.
    - The user can stop the input by typing `'s'`.

4. **Summation and Printing**:
    - After the input is complete, the program calculates the sum of the array’s elements and prints all the values.


