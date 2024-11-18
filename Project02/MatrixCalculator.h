#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H

#include <vector>
#include <iostream>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<double>> data; // Matrix data
    int rows, cols;                        // Dimensions of the matrix

public:
    // Constructor: Initialize a matrix with given dimensions
    Matrix(int r, int c);

    // Constructor: Initialize with predefined data
    Matrix(const std::vector<std::vector<double>>& inputData);

    // Getters
    int getRows() const;
    int getCols() const;
    double getElement(int row, int col) const;

    // Setters
    void setElement(int row, int col, double value);

    // Input and Display
    void inputMatrix();
    void displayMatrix() const;

    // Overloaded operators for matrix addition and subtraction
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;

    // Static Methods
    static Matrix multiply(const Matrix& A, const Matrix& B);
    static void qrDecomposition(const Matrix& A, Matrix& Q, Matrix& R);
    static std::vector<double> calculateEigenvalues(Matrix A, int maxIterations = 1000, double tolerance = 1e-10);
};

#endif // MATRIXCALCULATOR_H
