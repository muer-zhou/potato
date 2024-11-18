#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H

#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <iomanip>

class Matrix {
private:
    std::vector<std::vector<int>> data; // Matrix data
    int rows, cols;                     // Dimensions of the matrix

public:
    // Constructor
    Matrix(int r, int c);

    // Input and Output Methods
    void inputMatrix();
    void displayMatrix() const;

    // Overloaded Operators
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;

    // Static Methods
    static double dotProduct(const std::vector<double>& vec1, const std::vector<double>& vec2);
    static void crossProduct(const std::vector<double>& vec1, const std::vector<double>& vec2, std::vector<double>& result);
    static void gaussianElimination(std::vector<std::vector<double>> A, std::vector<double> b, std::vector<double>& x);
    static void qrDecomposition(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& Q, std::vector<std::vector<double>>& R);
    static bool isPositiveDefinite(const std::vector<std::vector<double>>& A);
    static std::vector<double> calculateEigenvalues(std::vector<std::vector<double>> A, int maxIterations = 1000, double tolerance = 1e-9);
};

#endif
