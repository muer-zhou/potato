#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<double>> data; // Matrix data
    int rows, cols;                        // Dimensions of the matrix

public:
    // Constructor: Initialize a matrix with given dimensions
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<double>(cols, 0.0)); // Initialize with zeros
    }

    // Constructor: Initialize with predefined data
    Matrix(const std::vector<std::vector<double>>& inputData)
        : data(inputData), rows(inputData.size()), cols(inputData[0].size()) {}

    // Getters
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    double getElement(int row, int col) const { return data[row][col]; }

    // Setters
    void setElement(int row, int col, double value) { data[row][col] = value; }

    // Input Method
    void inputMatrix() {
        std::cout << "Enter elements for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    // Display Method
    void displayMatrix() const {
        for (const auto& row : data) {
            for (const auto& element : row) {
                std::cout << std::setw(10) << std::fixed << std::setprecision(4) << element << " ";
            }
            std::cout << std::endl;
        }
    }

    // Overloaded + operator for matrix addition
    Matrix operator+(const Matrix& other) const {
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

    // Overloaded - operator for matrix subtraction
    Matrix operator-(const Matrix& other) const {
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

    // Static Dot Product Method
    static double dotProduct(const std::vector<double>& vec1, const std::vector<double>& vec2) {
        if (vec1.size() != vec2.size()) {
            throw std::invalid_argument("Vectors must be of the same size for dot product.");
        }
        double result = 0;
        for (size_t i = 0; i < vec1.size(); i++) {
            result += vec1[i] * vec2[i];
        }
        return result;
    }

    // Static Cross Product Method (only for three-dimensional vectors)
    static void crossProduct(const std::vector<double>& vec1, const std::vector<double>& vec2, std::vector<double>& result) {
        if (vec1.size() != 3 || vec2.size() != 3) {
            throw std::invalid_argument("Cross Product is only defined for three-dimensional vectors.");
        }
        result.assign(3, 0);
        result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
        result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
        result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
    }

    // Gaussian Elimination
    static void gaussianElimination(std::vector<std::vector<double>> A, std::vector<double> b, std::vector<double>& x) {
        const double EPS = 1e-9;
        int n = A.size();
        for (int i = 0; i < n; i++) A[i].push_back(b[i]); // Append b as the last column of A

        // Forward elimination
        for (int i = 0; i < n; i++) {
            int maxRow = i;
            for (int k = i + 1; k < n; k++) {
                if (fabs(A[k][i]) > fabs(A[maxRow][i])) maxRow = k;
            }
            std::swap(A[i], A[maxRow]);

            if (fabs(A[i][i]) < EPS) {
                throw std::runtime_error("No unique solution exists.");
            }

            for (int k = i + 1; k < n; k++) {
                double factor = A[k][i] / A[i][i];
                for (int j = i; j <= n; j++) A[k][j] -= factor * A[i][j];
            }
        }

        // Back substitution
        x.assign(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            x[i] = A[i][n] / A[i][i];
            for (int j = i - 1; j >= 0; j--) A[j][n] -= A[j][i] * x[i];
        }
    }

    // QR Decomposition
    static void qrDecomposition(const std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& Q, std::vector<std::vector<double>>& R) {
        int rows = A.size(), cols = A[0].size();
        Q.assign(rows, std::vector<double>(cols, 0));
        R.assign(cols, std::vector<double>(cols, 0));

        for (int k = 0; k < cols; k++) {
            // Compute Q_k
            for (int i = 0; i < rows; i++) Q[i][k] = A[i][k];
            for (int j = 0; j < k; j++) {
                double dot = 0;
                for (int i = 0; i < rows; i++) dot += Q[i][j] * A[i][k];
                R[j][k] = dot;
                for (int i = 0; i < rows; i++) Q[i][k] -= dot * Q[i][j];
            }

            // Normalize Q_k
            double norm = 0;
            for (int i = 0; i < rows; i++) norm += Q[i][k] * Q[i][k];
            norm = std::sqrt(norm);
            R[k][k] = norm;
            for (int i = 0; i < rows; i++) Q[i][k] /= norm;
        }
    }

    // Eigenvalue Calculation (using QR Algorithm)
    std::vector<double> calculateEigenvalues(std::vector<std::vector<double>> A, int maxIterations, double tolerance) {
        int n = A.size();
        std::vector<std::vector<double>> Q, R;

        for (int iter = 0; iter < maxIterations; iter++) {
            qrDecomposition(A, Q, R); // Decompose A into Q and R
            std::vector<std::vector<double>> newA(n, std::vector<double>(n, 0.0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        newA[i][j] += R[i][k] * Q[k][j];
                    }
                }
            }
            A = newA;

            // Check convergence
            bool converged = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (fabs(A[i][j]) > tolerance) {
                        converged = false;
                        break;
                    }
                }
            }
            if (converged) break;
        }

        std::vector<double> eigenvalues(n);
        for (int i = 0; i < n; i++) {
            eigenvalues[i] = A[i][i];
        }
        return eigenvalues;
    }


};
