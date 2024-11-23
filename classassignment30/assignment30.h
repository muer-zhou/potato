#ifndef ASSIGNMENT30_H
#define ASSIGNMENT30_H

#include <string>
#include <iostream>

class TextBox {
private:
    std::string value;

public:
    // Default constructor
    TextBox();

    // Explicit constructor that takes a string
    explicit TextBox(const std::string& text);

    // Setter for value
    void setValue(const std::string& text);

    // Getter for value
    std::string getValue() const;

    // Display the value
    void display() const;
};

#endif // ASSIGNMENT30_H
