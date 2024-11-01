# Assignment 21 - Dynamic Array with Smart Pointers

## Description
This program demonstrates the use of smart pointers (`shared_ptr`) for dynamic memory allocation in C++. The program dynamically allocates memory for an array, allows the user to input values, and automatically expands the array when more space is needed. The user can input numbers continuously, and the program will double the array's size whenever the current size is reached.

### Key Features:
- Utilizes **`shared_ptr`** for dynamic memory allocation, ensuring automatic memory management.
- Implements an **expand** function to resize the dynamically allocated array when it's full.
- The user can input an indefinite number of values until they type `'s'` to stop.
- After stopping, the program calculates the sum of all input numbers and prints the array and the sum.

## How to Use
1. **Compile the program** using a C++ compiler:
   ```bash
   g++ assignment.cpp -o dynamicArray
   ```

2. **Run the program**:
   ```bash
   ./dynamicArray
   ```

3. **Enter numbers** when prompted. Type `'s'` when you want to stop the input and see the results.

### Example Input:
```
Enter a number, or type 's' to stop: 10
Enter a number, or type 's' to stop: 20
Enter a number, or type 's' to stop: 30
Enter a number, or type 's' to stop: s
```

### Example Output:
```
The sum of the array will be: 60
10
20
30
0
```

### Important Notes:
- The array starts with size 1 and doubles in size whenever it reaches its maximum capacity.
- The sum is calculated for all the numbers entered, and the array contents (including any unfilled spots initialized to zero) are printed at the end.

## Code Structure
### Key Functions:
- `shared_ptr<int[]> expand(shared_ptr<int[]> &oldArr, int oldSize, int newSize)`
  - Dynamically expands the current array by creating a new larger array, copying the old values, and initializing the new spots to zero.
  
- `void printArray(shared_ptr<int[]> &arr, int size)`
  - Prints the contents of the array, element by element.

## Requirements
- A C++ compiler that supports **C++11** or later (for `shared_ptr`).
- Basic knowledge of compiling and running C++ programs.

## Class Information
- **Institution**: Berkeley City College
- **Class**: Computer Information Systems 25 (CIS 25)

## Notes
- **Smart Pointers**: The program uses `shared_ptr` for dynamic memory allocation, which manages memory automatically and prevents memory leaks.
- The program expands the array as needed when new numbers are added.
- The array doubles in size when filled to capacity to accommodate more numbers, which is a common practice to optimize dynamic array resizing.


## Files

- `assignment21.h` - Declares the `expand` and `printArray` functions.
- `assignment20.cpp` - Implements the `expand` and `printArray` functions.
- `main.cpp` - Main program that uses the functions to manage a dynamically expanding array.

## Compilation and Execution

To compile and run the program, use:

```bash
g++ main.cpp assignment20.cpp -o assignment20
./assignment20