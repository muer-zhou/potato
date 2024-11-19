#include "QuantumHarmonicOscillator.h"
#include "MatrixCalculator.h"
#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>
#include <fstream> // For exporting data
#include <chrono>
#include <thread> // For animation

// Function to print complex vectors
void printComplexVector(const std::vector<std::complex<double>>& vec) {
    for (const auto& val : vec) {
        std::cout << std::fixed << std::setprecision(6) << std::real(val) << " + " << std::imag(val) << "i\n";
    }
}

// Function to export wavefunction data to a file
void exportWavefunctionData(const std::vector<std::vector<std::complex<double>>>& wavefunctions,
                            const std::vector<double>& times, const std::string& filename) {
    std::ofstream file(filename);

    for (size_t t = 0; t < wavefunctions.size(); ++t) {
        file << "Time: " << times[t] << "\n";
        for (const auto& value : wavefunctions[t]) {
            file << std::real(value) << " " << std::imag(value) << "\n";
        }
        file << "\n"; // Separate time steps
    }

    file.close();
    std::cout << "Wavefunction data exported to " << filename << "\n";
}

// Function to simulate time evolution and display results
void simulateTimeEvolution(const Matrix& eigenvectors, const std::vector<double>& eigenvalues,
                           const std::vector<std::complex<double>>& initialState, double maxTime, double timeStep) {
    std::vector<std::vector<std::complex<double>>> wavefunctions;
    std::vector<double> times;

    for (double t = 0; t <= maxTime; t += timeStep) {
        auto evolvedState = timeEvolve(eigenvectors, eigenvalues, initialState, t);
        wavefunctions.push_back(evolvedState);
        times.push_back(t);

        // Display current wavefunction
        std::cout << "\nTime = " << t << ":\n";
        printComplexVector(evolvedState);

        // Add delay to simulate animation (optional)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Export wavefunction data
    exportWavefunctionData(wavefunctions, times, "wavefunction_evolution.dat");
}

int main() {
    try {
        std::cout << "=== Quantum Harmonic Oscillator Simulation ===\n";

        // Input parameters
        int gridPoints;
        double mass, omega, xMin, xMax, maxTime, timeStep;

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

        std::cout << "Enter the total time for time evolution (maxTime): ";
        std::cin >> maxTime;

        std::cout << "Enter the time step for simulation: ";
        std::cin >> timeStep;

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

        // Simulate time evolution
        simulateTimeEvolution(Q, eigenvalues, initialState, maxTime, timeStep);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
