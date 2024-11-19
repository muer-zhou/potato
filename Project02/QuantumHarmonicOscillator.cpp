#include "QuantumHarmonicOscillator.h"
#include "MatrixCalculator.h"
#include <cmath>
#include <stdexcept>
#include <complex>
#include <iostream>
#include <vector>

// Construct the Hamiltonian matrix
Matrix constructHamiltonian(int gridPoints, double mass, double omega, double xMin, double xMax) {
    if (gridPoints < 2) {
        throw std::invalid_argument("Grid points must be greater than or equal to 2.");
    }

    double dx = (xMax - xMin) / (gridPoints - 1);
    Matrix hamiltonian(gridPoints, gridPoints);

    for (int i = 0; i < gridPoints; i++) {
        double x = xMin + i * dx;
        double potential = 0.5 * mass * omega * omega * x * x;

        // Diagonal elements
        hamiltonian.setElement(i, i, 1.0 / (dx * dx) + potential);

        // Off-diagonal elements
        if (i > 0) {
            hamiltonian.setElement(i, i - 1, -1.0 / (2.0 * dx * dx));
        }
        if (i < gridPoints - 1) {
            hamiltonian.setElement(i, i + 1, -1.0 / (2.0 * dx * dx));
        }
    }

    return hamiltonian;
}

// Time-evolve the wavefunction
std::vector<std::complex<double>> timeEvolve(const Matrix& eigenvectors, const std::vector<double>& eigenvalues,
    const std::vector<std::complex<double>>& initialState, double time, double hbar) {
    int n = eigenvalues.size();
    std::vector<std::complex<double>> evolvedState(n, 0.0);

    for (int i = 0; i < n; ++i) {
        std::complex<double> coeff(0.0, 0.0);
        for (int j = 0; j < n; ++j) {
            coeff += std::conj(eigenvectors.getElement(j, i)) * initialState[j];
        }
        coeff *= std::exp(std::complex<double>(0, -eigenvalues[i] * time / hbar));

        for (int j = 0; j < n; ++j) {
            evolvedState[j] += coeff * eigenvectors.getElement(j, i);
        }
    }

    return evolvedState;
}
