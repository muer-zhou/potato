#ifndef QUANTUMHARMONICOSCILLATOR_H
#define QUANTUMHARMONICOSCILLATOR_H

#include <vector>
#include <stdexcept> // For exception handling

/**
 * Constructs the Hamiltonian matrix for a quantum harmonic oscillator.
 *
 * @param gridPoints The number of discrete grid points for the spatial dimension.
 * @param mass The mass of the particle in the oscillator.
 * @param omega The angular frequency of the oscillator.
 * @param xMin The minimum value of the spatial domain.
 * @param xMax The maximum value of the spatial domain.
 * @return A 2D vector representing the Hamiltonian matrix.
 * @throws std::invalid_argument If gridPoints < 2.
 */
std::vector<std::vector<double>> constructHamiltonian(int gridPoints, double mass, double omega, double xMin, double xMax);

#endif // QUANTUMHARMONICOSCILLATOR_H
