#include "QuantumHarmonicOscillator.h"
#include <vector>
#include <cmath>

std::vector<std::vector<double>> constructHamiltonian(int gridPoints, double mass, double omega, double xMin, double xMax) {
    if (gridPoints < 2) {
        throw std::invalid_argument("Grid points must be greater than or equal to 2.");
    }

    // Calculate grid spacing
    double dx = (xMax - xMin) / (gridPoints - 1);

    // Initialize the Hamiltonian matrix
    std::vector<std::vector<double>> hamiltonian(gridPoints, std::vector<double>(gridPoints, 0.0));

    // Fill the Hamiltonian matrix
    for (int i = 0; i < gridPoints; i++) {
        double x = xMin + i * dx;                              // Current grid point position
        double potential = 0.5 * mass * omega * omega * x * x; // Harmonic potential term

        // Diagonal element
        hamiltonian[i][i] = 1.0 / (dx * dx) + potential;

        // Off-diagonal elements (kinetic energy term)
        if (i > 0) {
            hamiltonian[i][i - 1] = -1.0 / (2.0 * dx * dx);
        }
        if (i < gridPoints - 1) {
            hamiltonian[i][i + 1] = -1.0 / (2.0 * dx * dx);
        }
    }

    return hamiltonian;
}
