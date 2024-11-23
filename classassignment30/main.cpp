#include "assignment30.h"
#include <iostream>

int main() {
    // Using the default constructor
    TextBox textBox1;
    textBox1.display();

    // Setting a value using the setter
    textBox1.setValue("Default constructor example");
    textBox1.display();

    // Using the explicit constructor
    TextBox textBox2("Explicit constructor example");
    textBox2.display();

    return 0;
}
