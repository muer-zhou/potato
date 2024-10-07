#include <iostream>
#include <cstdlib> // needed to use random number generator
#include <ctime> // needed for time()
using namespace std; 

// Function to generate random numbers for a matrix within a specific range
void matrixRandom(int arr[2][2], int row, int column, int minValue, int maxValue) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            // Generate a random number within the specified range
            arr[i][j] = (rand() % (maxValue - minValue + 1)) + minValue;
        }
    }
}

// Function to print a matrix
void printMatrix(int arr[2][2], int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to input a matrix from the user
void inputMatrix(int arr[2][2], int row, int column) {
    cout << "Please input the elements of the matrix (row by row):" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }
}

// Function to perform matrix calculations
void matrixCalculator(int arr1[2][2], int arr2[2][2], int row, int column, char operation) {
    switch (operation) {
        // Adding matrices
        case '+':
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    arr1[i][j] = arr1[i][j] + arr2[i][j];
                }
            }
            break;
        // Subtracting Matrices
        case '-':
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    arr1[i][j] = arr1[i][j] - arr2[i][j];
                }
            }
            break;
        // Multiplying Matrices
        case '*':
            int temp[2][2];
            temp[0][0] = arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0];
            temp[0][1] = arr1[0][0] * arr2[0][1] + arr1[0][1] * arr2[1][1];
            temp[1][0] = arr1[1][0] * arr2[0][0] + arr1[1][1] * arr2[1][0];
            temp[1][1] = arr1[1][0] * arr2[0][1] + arr1[1][1] * arr2[1][1];

            // Copy the result into arr1
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    arr1[i][j] = temp[i][j];
                }
            }
            break;
    }
}

// Function to check if the user's input matrix matches the actual result
bool checkMatrix(int userMatrix[2][2], int correctMatrix[2][2], int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (userMatrix[i][j] != correctMatrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    srand(time(0));  // Seed the random number generator

    int arr1[2][2], arr2[2][2], arr3[2][2];  // arr3 will store the user's answer
    int row = 2, column = 2;
    char operation;

    // Define the range for random numbers
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 9;

     // Progress tracking variables
    int correctCount = 0;
    int incorrectCount = 0;
    
    // Generate random values for the matrices within the range
    matrixRandom(arr1, row, column, MIN_VALUE, MAX_VALUE);
    matrixRandom(arr2, row, column, MIN_VALUE, MAX_VALUE);

    cout << "Welcome to the Linear Algebra tutor!" << endl;
    cout << "You will be given two random matrices" << endl;
    
    // Display the randomly generated matrices
    cout << "Matrix 1:\n";
    printMatrix(arr1, row, column);

    cout << "Matrix 2:\n";
    printMatrix(arr2, row, column);
    
    // Get the operation input from the user
    cout << "You are given the option to choose what Matrix operations you like to practice with" << endl;
    cout << "Enter the operation (+, -, *): ";
    cin >> operation;

    // Perform the matrix calculation
    matrixCalculator(arr1, arr2, row, column, operation);

    // Ask for the user's answer
    cout << "What is your answer?" << endl;
    inputMatrix(arr3, row, column);  // Allow the user to input their answer into arr3

    // Display the correct result
    cout << "Correct Resultant Matrix:\n";
    printMatrix(arr1, row, column);

    // Check if the user's answer matches the correct result
    if (checkMatrix(arr3, arr1, row, column)) {
        cout << "Correct! Your answer matches the result." << endl;
        correctCount++;
    } else {
        cout << "Incorrect. Your answer does not match the result." << endl;
        incorrectCount++;
    }

    cout << "Progress: " << correctCount << " correct, " << incorrectCount << " incorrect." << endl;

    

    return 0;
}

