### **Project 2 : Quantum Harmonic Oscillator Project**

---

## **Project Overview**
This program simulates the **Quantum Harmonic Oscillator** using numerical methods. It constructs the Hamiltonian matrix, computes eigenvalues and eigenvectors, and simulates the time evolution of an initial wavefunction. The results provide insights into quantum mechanics and demonstrate key concepts such as energy levels, wavefunctions, and time evolution.

---

## **Features**
1. **Hamiltonian Construction**:
   - Constructs the Hamiltonian matrix for a particle in a harmonic potential.
   - Incorporates both kinetic and potential energy terms.

2. **Eigenvalue and Eigenvector Calculation**:
   - Uses QR decomposition to compute the eigenvalues (energy levels) and eigenvectors (eigenstates).

3. **Time Evolution**:
   - Simulates the time evolution of an initial wavefunction using eigenvalues and eigenvectors.

4. **Initial Wavefunction**:
   - The default is a **Gaussian wavefunction**, representing a particle localized near the origin.

5. **User Interaction**:
   - Accepts user input for grid points, particle mass, angular frequency, range of \(x\), and time of evolution.

---

## **How to Compile and Run**

### **1. Prerequisites**
- A C++17 compatible compiler (e.g., `g++`).
- Basic command-line experience.

### **2. Compilation**
Run the following command to compile the program:
```bash
g++ main.cpp QuantumHarmonicOscillator.cpp MatrixCalculator.cpp -o QuantumHarmonicOscillator -std=c++17
```

### **3. Execution**
Run the program with:
```bash
./QuantumHarmonicOscillator
```

---

## **Usage**

### **Input Parameters**
The program prompts the user for the following inputs:
1. **Number of Grid Points**: Discretizes the spatial range for the simulation.
2. **Mass of the Particle**: The mass of the quantum particle.
3. **Angular Frequency (\( \omega \))**: Determines the shape of the harmonic potential.
4. **Minimum and Maximum \( x \)**: The range of positions for the simulation.
5. **Time for Evolution (\( t \))**: Simulates the wavefunction's evolution over this time.

### **Example Run**
```
=== Quantum Harmonic Oscillator Simulation ===
Enter the number of grid points: 5
Enter the mass of the particle: 1.0
Enter the angular frequency (omega): 1.0
Enter the minimum x value (xMin): -5.0
Enter the maximum x value (xMax): 5.0
Enter the time for time evolution (t): 1.0
```

---

### **Output**
1. **Hamiltonian Matrix**:
   - The Hamiltonian matrix includes kinetic and potential energy terms.

2. **Eigenvalues**:
   - The energy levels of the quantum harmonic oscillator.

3. **Time-Evolved Wavefunction**:
   - The wavefunction \( \psi(x, t) \) at the given time \( t \).

Example Output:
```
Hamiltonian Matrix:
    12.660000  -0.080000   0.000000   0.000000   0.000000 
    -0.080000   3.285000  -0.080000   0.000000   0.000000 
     0.000000  -0.080000   0.160000  -0.080000   0.000000 
     0.000000   0.000000  -0.080000   3.285000  -0.080000 
     0.000000   0.000000   0.000000  -0.080000  12.660000 

Eigenvalues:
12.660000 3.285000 0.160000 3.285000 12.660000 

Time-Evolved Wavefunction (t = 1.000000):
0.995620 + -0.093493i
0.000000 + 0.000000i
0.000000 + 0.000000i
0.000000 + 0.000000i
0.000000 + 0.000000i
```

---

## **How It Works**
1. **Hamiltonian Construction**:
   - The spatial range (\(x_{\text{min}}\) to \(x_{\text{max}}\)) is divided into `gridPoints`.
   - A second-order finite difference method is used to approximate the kinetic energy operator.
   - The harmonic potential term is added to the diagonal elements.

2. **Eigenvalue and Eigenvector Calculation**:
   - The eigenvalues represent the energy levels of the quantum harmonic oscillator.
   - The eigenvectors are the wavefunctions corresponding to each energy level.

3. **Time Evolution**:
   - The wavefunction is expressed as a linear combination of eigenstates.
   - Each eigenstate evolves in time as:
     \[
     \psi_n(t) = \psi_n(0) e^{-i E_n t / \hbar}
     \]

---

## **Files and Their Roles**
1. **`MatrixCalculator.h` and `MatrixCalculator.cpp`**:
   - Defines a `Matrix` class for handling matrix operations such as multiplication, QR decomposition, and eigenvalue calculations.

2. **`QuantumHarmonicOscillator.h` and `QuantumHarmonicOscillator.cpp`**:
   - Provides functions for constructing the Hamiltonian, computing eigenvalues/eigenvectors, and performing time evolution.

3. **`main.cpp`**:
   - The entry point for the program.
   - Handles user input, invokes functions from the above modules, and displays results.

---

## **Features to Explore**
1. Experiment with different values for:
   - **Grid Points**: Increase to improve accuracy.
   - **Mass and Omega**: Observe how energy levels and wavefunctions change.
   - **Time Evolution**: Simulate how the wavefunction evolves over time.

2. Extend the project to:
   - **Include perturbations** (e.g., a constant electric field).
   - **Visualize results** using ASCII plots or external tools like Python.

---

## **Future Improvements**
- Implement numerical libraries for more accurate eigenvalue/eigenvector calculations (e.g., Eigen or LAPACK).
- Add support for perturbation theory or multi-dimensional oscillators.
- Generate plots directly within the program (e.g., using `gnuplot`).

---

## **Contact**
If you encounter any issues or have suggestions for improvement, feel free to reach out!

Happy Simulating! 🎉
