#include <iostream>
#include <vector>
#include <iomanip>
#include "QuantumHarmonicOscillator.h"

/**
 * Function to print a 2D matrix (for displaying the Hamiltonian).
 * @param matrix The 2D vector to print.
 */
void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    try {
        // Input parameters
        int gridPoints;
        double mass, omega, xMin, xMax;

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

        // Construct the Hamiltonian matrix
        std::vector<std::vector<double>> hamiltonian = constructHamiltonian(gridPoints, mass, omega, xMin, xMax);

        // Print the Hamiltonian matrix
        std::cout << "\nHamiltonian Matrix:\n";
        printMatrix(hamiltonian);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
