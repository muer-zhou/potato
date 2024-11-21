### **README: Double to String Conversion Utility**

---

#### **Overview**
This program provides a reusable function for converting `double` values to formatted strings using `std::stringstream`. The function formats the double value to one decimal place and is encapsulated in a modular design.

---

#### **Features**
1. Converts `double` values to formatted `std::string`.
2. Formats the string to show a fixed-point number with one decimal precision.

---

#### **Files**
1. **convert.h**: Declares the reusable function `convertDoubleToString`.
2. **convert.cpp**: Implements the function using `std::stringstream`.
3. **main.cpp**: Demonstrates the usage of the function.

---

#### **Compilation**
Use the following command to compile the program:

```bash
g++ main.cpp convert.cpp -o convert
```

---

