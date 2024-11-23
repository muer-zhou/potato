#include "assignment30.h"

// Default constructor
TextBox::TextBox() : value("") {}

// Explicit constructor
TextBox::TextBox(const std::string& text) : value(text) {}

// Setter for value
void TextBox::setValue(const std::string& text) {
    value = text;
}

// Getter for value
std::string TextBox::getValue() const {
    return value;
}

// Display the value
void TextBox::display() const {
    std::cout << "TextBox value: " << value << std::endl;
}
