#include <iostream>
#include <fstream> // Include this for file operations
#include "MatrixCalculator.h"
#include "QuantumHarmonicOscillator.h"

int main() {
    std::cout << "=== Quantum Harmonic Oscillator ===\n";

    int gridPoints;
    std::cout << "Enter the number of grid points: ";
    std::cin >> gridPoints;

    double mass;
    std::cout << "Enter the mass of the particle: ";
    std::cin >> mass;

    double omega;
    std::cout << "Enter the angular frequency (omega): ";
    std::cin >> omega;

    double xMin, xMax;
    std::cout << "Enter the minimum x value: ";
    std::cin >> xMin;
    std::cout << "Enter the maximum x value: ";
    std::cin >> xMax;

    // Construct Hamiltonian matrix
    std::vector<std::vector<double>> hamiltonian = constructHamiltonian(gridPoints, mass, omega, xMin, xMax);

    // Calculate eigenvalues using the Matrix class
    std::cout << "Calculating eigenvalues...\n";
    std::vector<double> eigenvalues = Matrix::calculateEigenvalues(hamiltonian);

    // Save eigenvalues to a file
    std::ofstream outFile("harmonic_oscillator_eigenvalues.txt"); // Correctly include <fstream>
    if (outFile.is_open()) {
        outFile << "Eigenvalues of the Quantum Harmonic Oscillator:\n";
        for (size_t i = 0; i < eigenvalues.size(); i++) {
            outFile << "Eigenvalue " << i + 1 << ": " << eigenvalues[i] << "\n";
        }
        outFile.close();
        std::cout << "Eigenvalues saved to harmonic_oscillator_eigenvalues.txt\n";
    } else {
        std::cerr << "Error: Could not open the file for writing.\n";
    }

    return 0;
}
