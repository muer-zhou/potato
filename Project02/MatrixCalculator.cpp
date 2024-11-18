#include "MatrixCalculator.h"
#include <iomanip>
#include <cmath>
#include <iostream>
#include <stdexcept>

// Constructor: Initialize a matrix with given dimensions
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(rows, std::vector<double>(cols, 0.0));
}

// Constructor: Initialize with predefined data
Matrix::Matrix(const std::vector<std::vector<double>>& inputData)
    : data(inputData), rows(inputData.size()), cols(inputData[0].size()) {}

// Getters
int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }
double Matrix::getElement(int row, int col) const { return data[row][col]; }

// Setters
void Matrix::setElement(int row, int col, double value) { data[row][col] = value; }

// Input and Display
void Matrix::inputMatrix() {
    std::cout << "Enter elements for a " << rows << "x" << cols << " matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> data[i][j];
        }
    }
}

void Matrix::displayMatrix() const {
    for (const auto& row : data) {
        for (const auto& element : row) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << element << " ";
        }
        std::cout << std::endl;
    }
}

// Overloaded operators for matrix addition and subtraction
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Matrix Multiplication
Matrix Matrix::multiply(const Matrix& A, const Matrix& B) {
    if (A.getCols() != B.getRows()) {
        throw std::invalid_argument("Matrix dimensions must match for multiplication.");
    }
    Matrix result(A.getRows(), B.getCols());
    for (int i = 0; i < A.getRows(); i++) {
        for (int j = 0; j < B.getCols(); j++) {
            for (int k = 0; k < A.getCols(); k++) {
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return result;
}

// QR Decomposition
void Matrix::qrDecomposition(const Matrix& A, Matrix& Q, Matrix& R) {
    int rows = A.getRows(), cols = A.getCols();
    Q = Matrix(rows, cols);
    R = Matrix(cols, cols);

    for (int k = 0; k < cols; k++) {
        for (int i = 0; i < rows; i++) Q.data[i][k] = A.data[i][k];
        for (int j = 0; j < k; j++) {
            double dot = 0.0;
            for (int i = 0; i < rows; i++) dot += Q.data[i][j] * A.data[i][k];
            R.data[j][k] = dot;
            for (int i = 0; i < rows; i++) Q.data[i][k] -= dot * Q.data[i][j];
        }
        double norm = 0.0;
        for (int i = 0; i < rows; i++) norm += Q.data[i][k] * Q.data[i][k];
        norm = std::sqrt(norm);
        R.data[k][k] = norm;
        for (int i = 0; i < rows; i++) Q.data[i][k] /= norm;
    }
}

// Eigenvalue Calculation
std::vector<double> Matrix::calculateEigenvalues(Matrix A, int maxIterations, double tolerance) {
    if (A.getRows() != A.getCols()) {
        throw std::invalid_argument("Matrix must be square for eigenvalue calculation.");
    }

    int n = A.getRows();
    Matrix Q(n, n), R(n, n);

    for (int iter = 0; iter < maxIterations; iter++) {
        qrDecomposition(A, Q, R);
        A = multiply(R, Q);

        bool converged = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (std::fabs(A.data[i][j]) > tolerance) {
                    converged = false;
                    break;
                }
            }
        }
        if (converged) break;
    }

    std::vector<double> eigenvalues(n);
    for (int i = 0; i < n; i++) {
        eigenvalues[i] = A.data[i][i];
    }
    return eigenvalues;
}
