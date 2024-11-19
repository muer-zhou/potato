#ifndef QUANTUMHARMONICOSCILLATOR_H
#define QUANTUMHARMONICOSCILLATOR_H

#include "MatrixCalculator.h"
#include <vector>
#include <complex>

// Function to construct the Hamiltonian matrix
Matrix constructHamiltonian(int gridPoints, double mass, double omega, double xMin, double xMax);

// Function to perform time evolution of the wavefunction
std::vector<std::complex<double>> timeEvolve(const Matrix& eigenvectors, const std::vector<double>& eigenvalues,
                                             const std::vector<std::complex<double>>& initialState, double time, double hbar = 1.0);

#endif
