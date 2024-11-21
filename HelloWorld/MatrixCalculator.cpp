#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to multiply two square matrices
vector<vector<double>> multiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int n = A.size();
    vector<vector<double>> result(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to compute the dot product of two vectors
double dotProduct(const vector<double>& v1, const vector<double>& v2) {
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Function to normalize a vector
void normalize(vector<double>& vec) {
    double norm = sqrt(dotProduct(vec, vec));
    if (norm < 1e-10) { // Prevent division by zero
        throw runtime_error("Norm too small; cannot normalize.");
    }
    for (double& val : vec) {
        val /= norm;
    }
}

// Function to perform QR decomposition
void qrDecomposition(const vector<vector<double>>& A, vector<vector<double>>& Q, vector<vector<double>>& R) {
    int n = A.size();
    Q = vector<vector<double>>(n, vector<double>(n, 0.0));
    R = vector<vector<double>>(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        // Copy column i of A into Q
        for (int j = 0; j < n; j++) {
            Q[j][i] = A[j][i];
        }

        // Subtract projections onto previous columns
        for (int j = 0; j < i; j++) {
            double proj = dotProduct(Q[j], Q[i]);
            R[j][i] = proj;
            for (int k = 0; k < n; k++) {
                Q[k][i] -= proj * Q[k][j];
            }
        }

        // Normalize the column
        R[i][i] = sqrt(dotProduct(Q[i], Q[i]));
        if (R[i][i] < 1e-10) {
            throw runtime_error("Matrix is rank deficient; cannot compute QR decomposition.");
        }
        for (int j = 0; j < n; j++) {
            Q[j][i] /= R[i][i];
        }
    }
}

bool isSymmetric(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fabs(A[i][j] - A[j][i]) > 1e-10) { // Allow small numerical differences
                return false;
            }
        }
    }
    return true;
}


// QR Algorithm to compute eigenvalues
vector<double> computeEigenvalues(vector<vector<double>> A, int maxIterations = 1000, double tolerance = 1e-10) {
    int n = A.size();
    vector<vector<double>> Q, R;

    for (int iter = 0; iter < maxIterations; iter++) {
        qrDecomposition(A, Q, R);  // Decompose A into Q and R
        A = multiply(R, Q);        // Update A = R * Q

        // Check for convergence: if off-diagonal elements are close to zero
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

        // Debugging: print the matrix after each iteration
        cout << "Iteration " << iter + 1 << ": Matrix A = " << endl;
        for (const auto& row : A) {
            for (double val : row) {
                cout << setw(10) << val << " ";
            }
            cout << endl;
        }
    }

    // Extract eigenvalues from the diagonal of A
    vector<double> eigenvalues(n);
    for (int i = 0; i < n; i++) {
        eigenvalues[i] = A[i][i];
    }
    return eigenvalues;
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    cout << "Enter the matrix elements row by row (use spaces to separate values):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Check if the matrix is symmetric
    if (!isSymmetric(A)) {
        cerr << "Error: The matrix is not symmetric. The QR algorithm requires a symmetric matrix." << endl;
        return 1;
    }

    try {
        // Compute eigenvalues
        vector<double> eigenvalues = computeEigenvalues(A);

        // Print eigenvalues
        cout << fixed << setprecision(6);
        cout << "Eigenvalues:" << endl;
        for (double eigenvalue : eigenvalues) {
            cout << eigenvalue << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
