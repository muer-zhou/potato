#ifndef QUANTUMHARMONICOSCILLATOR_H
#define QUANTUMHARMONICOSCILLATOR_H

#include <vector>
#include <complex>

// Constructs the Hamiltonian matrix
std::vector<std::vector<double>> constructHamiltonian(int gridPoints, double mass, double omega, double xMin, double xMax);

// Computes eigenvalues and eigenvectors of the Hamiltonian
void computeEigenvaluesAndEigenvectors(const std::vector<std::vector<double>>& hamiltonian, 
    std::vector<double>& eigenvalues, 
    std::vector<std::vector<double>>& eigenvectors);

// Computes the time-evolved wavefunction
std::vector<std::complex<double>> timeEvolve(const std::vector<std::vector<double>>& eigenvectors, 
    const std::vector<double>& eigenvalues, 
    const std::vector<std::complex<double>>& initialState, 
    double time, double hbar = 1.0);

#endif
