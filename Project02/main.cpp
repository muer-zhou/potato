#include "QuantumHarmonicOscillator.h"
#include "MatrixCalculator.h"
#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>

void printComplexVector(const std::vector<std::complex<double>>& vec) {
    for (const auto& val : vec) {
        std::cout << std::real(val) << " + " << std::imag(val) << "i\n";
    }
}

int main() {
    try {
        std::cout << "=== Quantum Harmonic Oscillator Simulation ===\n";
        int gridPoints;
        double mass, omega, xMin, xMax, time;

        // Input parameters
        std::cout << "Enter the number of grid points: ";
        std::cin >> gridPoints;

        std::cout << "Enter the mass of the particle: ";
        std::cin >> mass;

        std::cout << "Enter the angular frequency (omega): ";
        std::cin >> omega;

        std::cout << "Enter the minimum x value (xMin): ";
        std::cin >> xMin;

        std::cout << "Enter the maximum x value (xMax): ";
        std::cin >> xMax;

        std::cout << "Enter the time for time evolution (t): ";
        std::cin >> time;

        // Construct the Hamiltonian
        Matrix hamiltonian = constructHamiltonian(gridPoints, mass, omega, xMin, xMax);
        std::cout << "\nHamiltonian Matrix:\n";
        hamiltonian.displayMatrix();

        // Compute eigenvalues and eigenvectors
        std::vector<double> eigenvalues = hamiltonian.calculateEigenvalues(hamiltonian, 100, 1e-10);
        Matrix Q(gridPoints, gridPoints), R(gridPoints, gridPoints);
        hamiltonian.qrDecomposition(hamiltonian, Q, R);

        std::cout << "\nEigenvalues:\n";
        for (double val : eigenvalues) {
            std::cout << std::fixed << std::setprecision(6) << val << "\n";
        }

        // Generate a Gaussian wavefunction
        std::vector<std::complex<double>> initialState(gridPoints, 0.0);
        double dx = (xMax - xMin) / (gridPoints - 1);
        for (int i = 0; i < gridPoints; ++i) {
            double x = xMin + i * dx;
            initialState[i] = std::exp(-x * x); // Gaussian wavefunction
        }

        // Perform time evolution
        auto evolvedState = timeEvolve(Q, eigenvalues, initialState, time);

        std::cout << "\nTime-Evolved Wavefunction (t = " << time << "):\n";
        printComplexVector(evolvedState);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
