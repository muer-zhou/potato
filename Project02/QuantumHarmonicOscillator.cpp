#include "QuantumHarmonicOscillator.h"

std::vector<std::vector<double>> constructHamiltonian(int gridPoints, double mass, double omega, double xMin, double xMax) {
    double dx = (xMax - xMin) / (gridPoints - 1);
    std::vector<std::vector<double>> hamiltonian(gridPoints, std::vector<double>(gridPoints, 0));

    for (int i = 0; i < gridPoints; i++) {
        double x = xMin + i * dx;
        double potential = 0.5 * mass * omega * omega * x * x;

        if (i > 0) hamiltonian[i][i - 1] = -1.0 / (2.0 * dx * dx);
        hamiltonian[i][i] = 1.0 / (dx * dx) + potential;
        if (i < gridPoints - 1) hamiltonian[i][i + 1] = -1.0 / (2.0 * dx * dx);
    }

    return hamiltonian;
}
