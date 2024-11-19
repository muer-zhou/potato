### **README for Quantum Harmonic Oscillator Project**

---

## **Project Overview**
This program simulates the **Quantum Harmonic Oscillator** by numerically constructing the Hamiltonian matrix, calculating eigenvalues and eigenvectors, and simulating the time evolution of a wavefunction. It exports wavefunction data over time for visualization and analysis.

---

## **Features**
1. **Hamiltonian Construction**:
   - Constructs the Hamiltonian matrix using a finite difference method.
   - Incorporates kinetic and potential energy terms.

2. **Eigenvalue and Eigenvector Calculation**:
   - Uses QR decomposition to compute eigenvalues (energy levels) and eigenvectors (wavefunctions).

3. **Time Evolution of Wavefunction**:
   - Simulates the wavefunction's time evolution based on eigenstates.
   - Outputs the wavefunction values at user-defined time steps.

4. **Data Export**:
   - Saves the wavefunction values to `wavefunction_evolution.dat` for further analysis or visualization.

5. **Interactive User Inputs**:
   - The user can define grid points, particle mass, angular frequency, spatial range, time range, and time step.

---

## **How to Compile and Run**

### **1. Prerequisites**
- A C++17 compatible compiler (e.g., `g++`).
- Optional: Python or Gnuplot for visualization.

### **2. Compilation**
Compile the project with:
```bash
g++ main.cpp QuantumHarmonicOscillator.cpp MatrixCalculator.cpp -o QuantumHarmonicOscillator -std=c++17
```

### **3. Execution**
Run the program:
```bash
./QuantumHarmonicOscillator
```

---

## **Usage**

### **Input Parameters**
The program prompts the user for the following inputs:
1. **Number of Grid Points**: Determines the spatial resolution.
2. **Mass of the Particle**: Physical mass of the quantum particle.
3. **Angular Frequency (\( \omega \))**: Determines the potential well's width.
4. **Minimum and Maximum \( x \)**: The spatial range of the simulation.
5. **Maximum Time (\( t_{\text{max}} \))**: Total duration of the simulation.
6. **Time Step (\( \Delta t \))**: Interval between time evolution steps.

---

### **Example Input**
```
Enter the number of grid points: 5
Enter the mass of the particle: 1
Enter the angular frequency (omega): 1
Enter the minimum x value (xMin): -5
Enter the maximum x value (xMax): 5
Enter the total time for time evolution (maxTime): 5
Enter the time step for simulation: 1
```

### **Output**
1. **Hamiltonian Matrix**:
   - Displays the Hamiltonian matrix constructed for the harmonic oscillator.

2. **Eigenvalues**:
   - Lists the computed eigenvalues (energy levels).

3. **Wavefunction at Each Time Step**:
   - Displays the wavefunction \( \psi(x, t) \) as a complex number for each grid point at user-defined time intervals.

4. **Data Export**:
   - Saves wavefunction data to `wavefunction_evolution.dat`.

#### Example Output:
```
Hamiltonian Matrix:
   12.6600    -0.0800     0.0000     0.0000     0.0000 
   -0.0800     3.2850    -0.0800     0.0000     0.0000 
    0.0000    -0.0800     0.1600    -0.0800     0.0000 
    0.0000     0.0000    -0.0800     3.2850    -0.0800 
    0.0000     0.0000     0.0000    -0.0800    12.6600 

Eigenvalues:
12.660683
12.660683
3.286614
3.286112
0.155909

Time = 0.000000:
0.000000 + 0.000000i
...

Wavefunction data exported to wavefunction_evolution.dat
```

---

## **Visualizing the Results**

### **1. Exported Data**
The file `wavefunction_evolution.dat` contains:
- Time steps.
- Wavefunction values (real and imaginary parts).

#### Example:
```
Time: 0.0
0.000000 0.000000
0.001930 0.000000
1.000000 0.000000
...

Time: 1.0
-0.000305 0.000037
-0.046394 0.005625
...
```

---

### **2. Plotting with Python**
Use the exported data to plot the wavefunction evolution. Below is a Python script using **Matplotlib**:

```python
import numpy as np
import matplotlib.pyplot as plt

# Load data
data = []
time_blocks = []
with open("wavefunction_evolution.dat", "r") as file:
    current_time = None
    current_wavefunction = []
    for line in file:
        if line.startswith("Time:"):
            if current_wavefunction:
                data.append((current_time, np.abs(np.array(current_wavefunction))**2))
            current_time = float(line.split()[1])
            current_wavefunction = []
        elif line.strip():
            real, imag = map(float, line.split())
            current_wavefunction.append(complex(real, imag))
    if current_wavefunction:
        data.append((current_time, np.abs(np.array(current_wavefunction))**2))

# Plot the data
for time, wavefunction in data:
    x = np.linspace(-5, 5, len(wavefunction))  # Adjust x range based on your simulation
    plt.plot(x, wavefunction, label=f't = {time:.1f}')

plt.xlabel('Position (x)')
plt.ylabel('|ψ(x, t)|² (Probability Density)')
plt.title('Wavefunction Time Evolution')
plt.legend()
plt.show()
```

Run this script to generate the wavefunction evolution graph.

---

### **3. Alternative: ASCII Visualization**
For simple visualization directly in the terminal, implement an ASCII-based wavefunction plot:
```cpp
void visualizeWavefunctionASCII(const std::vector<std::complex<double>>& wavefunction, double scale = 10.0) {
    for (const auto& value : wavefunction) {
        int numStars = static_cast<int>(std::abs(value) * scale);
        for (int i = 0; i < numStars; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}
```

Call `visualizeWavefunctionASCII()` after each time step to see the probability density in real time.

---

## **How It Works**
1. **Hamiltonian Construction**:
   - Uses a finite difference method for the kinetic energy term.
   - Adds the harmonic potential for diagonal elements.

2. **Eigenvalue Computation**:
   - Decomposes the Hamiltonian into eigenvalues and eigenvectors using QR decomposition.

3. **Time Evolution**:
   - Evolves the initial wavefunction over time using:
     \[
     \psi(x, t) = \sum_n c_n \phi_n(x) e^{-iE_nt/\hbar}
     \]

4. **Export and Plotting**:
   - Outputs time-dependent wavefunctions for further visualization.

---

## **Future Improvements**
- **Advanced Visualizations**:
  - Integrate libraries like **Matplotlib C++**, **Gnuplot**, or export directly to plotting software.
- **Additional Features**:
  - Add support for perturbations or multi-dimensional oscillators.
- **Interactive Graphics**:
  - Use external libraries like SFML or OpenGL for dynamic, real-time 3D visualizations.

---

## **Contact**
If you have any issues or ideas to improve this project, feel free to reach out!

Happy Coding and Simulating! 🎉