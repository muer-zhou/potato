#include "QuantumHarmonicOscillator.h"
#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>
#include <cmath>

// Helper function to print vectors
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << std::fixed << std::setprecision(6) << val << " ";
    }
    std::cout << std::endl;
}

// Helper function to print matrices
void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(6) << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    try {
        // Collect user inputs
        int gridPoints;
        double mass, omega, xMin, xMax, time;

        std::cout << "=== Quantum Harmonic Oscillator Simulation ===\n";
        std::cout << "Enter the number of grid points: ";
        std::cin >> gridPoints;

        if (gridPoints < 2) {
            throw std::invalid_argument("Grid points must be at least 2.");
        }

        std::cout << "Enter the mass of the particle: ";
        std::cin >> mass;

        std::cout << "Enter the angular frequency (omega): ";
        std::cin >> omega;

        std::cout << "Enter the minimum x value (xMin): ";
        std::cin >> xMin;

        std::cout << "Enter the maximum x value (xMax): ";
        std::cin >> xMax;

        if (xMax <= xMin) {
            throw std::invalid_argument("xMax must be greater than xMin.");
        }

        std::cout << "Enter the time for time evolution (t): ";
        std::cin >> time;

        // Construct the Hamiltonian matrix
        std::vector<std::vector<double>> hamiltonian = constructHamiltonian(gridPoints, mass, omega, xMin, xMax);
        std::cout << "\nHamiltonian Matrix:\n";
        printMatrix(hamiltonian);

        // Compute eigenvalues and eigenvectors
        std::vector<double> eigenvalues;
        std::vector<std::vector<double>> eigenvectors;
        computeEigenvaluesAndEigenvectors(hamiltonian, eigenvalues, eigenvectors);

        std::cout << "\nEigenvalues:\n";
        printVector(eigenvalues);

        // Collect initial wavefunction from the user
        std::vector<std::complex<double>> initialState(gridPoints, 0.0);
        std::cout << "\nEnter the initial wavefunction values (real part only, separated by spaces):\n";
        for (int i = 0; i < gridPoints; ++i) {
            double realPart;
            std::cin >> realPart;
            initialState[i] = std::complex<double>(realPart, 0.0);
        }

        // Time evolution
        std::vector<std::complex<double>> evolvedState = timeEvolve(eigenvectors, eigenvalues, initialState, time);

        std::cout << "\nTime-Evolved Wavefunction (t = " << time << "):\n";
        for (const auto& value : evolvedState) {
            std::cout << std::real(value) << " + " << std::imag(value) << "i\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
