#include "QuantumHarmonicOscillator.h"
#include <cmath>
#include <stdexcept>
#include <complex>
#include <iostream>

// Constructs the Hamiltonian matrix
std::vector<std::vector<double>> constructHamiltonian(int gridPoints, double mass, double omega, double xMin, double xMax) {
    if (gridPoints < 2) {
        throw std::invalid_argument("Grid points must be greater than or equal to 2.");
    }

    double dx = (xMax - xMin) / (gridPoints - 1);
    std::vector<std::vector<double>> hamiltonian(gridPoints, std::vector<double>(gridPoints, 0.0));

    for (int i = 0; i < gridPoints; i++) {
        double x = xMin + i * dx;
        double potential = 0.5 * mass * omega * omega * x * x;

        hamiltonian[i][i] = 1.0 / (dx * dx) + potential;
        if (i > 0) hamiltonian[i][i - 1] = -1.0 / (2.0 * dx * dx);
        if (i < gridPoints - 1) hamiltonian[i][i + 1] = -1.0 / (2.0 * dx * dx);
    }

    return hamiltonian;
}

// Computes eigenvalues and eigenvectors
void computeEigenvaluesAndEigenvectors(const std::vector<std::vector<double>>& hamiltonian, 
                                       std::vector<double>& eigenvalues, 
                                       std::vector<std::vector<double>>& eigenvectors) {
    int n = hamiltonian.size();
    eigenvalues.resize(n);
    eigenvectors.resize(n, std::vector<double>(n, 0.0));

    // Placeholder implementation: Replace with a real eigenvalue solver.
    for (int i = 0; i < n; ++i) {
        eigenvalues[i] = hamiltonian[i][i];
        eigenvectors[i][i] = 1.0;
    }
}

// Computes the time-evolved wavefunction
std::vector<std::complex<double>> timeEvolve(const std::vector<std::vector<double>>& eigenvectors, 
                                             const std::vector<double>& eigenvalues, 
                                             const std::vector<std::complex<double>>& initialState, 
                                             double time, double hbar) {
    int n = eigenvalues.size();
    std::vector<std::complex<double>> evolvedState(n, 0.0);

    for (int i = 0; i < n; ++i) {
        std::complex<double> coeff(0.0, 0.0);
        for (int j = 0; j < n; ++j) {
            coeff += std::conj(eigenvectors[j][i]) * initialState[j];
        }
        coeff *= std::exp(std::complex<double>(0, -eigenvalues[i] * time / hbar));

        for (int j = 0; j < n; ++j) {
            evolvedState[j] += coeff * eigenvectors[j][i];
        }
    }

    return evolvedState;
}
