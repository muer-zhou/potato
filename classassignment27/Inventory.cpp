#include "Inventory.h"
#include <iostream>

namespace bookstore {

    // Add a book to the inventory
    void Inventory::addBook(const Book& book) {
        books.push_back(book);
    }

    // Find a book by its ISBN
    Book* Inventory::findBook(const std::string& isbn) {
        for (auto& book : books) {
            if (book.isbn == isbn) {
                return &book; // Return a pointer to the book if found
            }
        }
        return nullptr; // Return nullptr if the book is not found
    }

    // Display all books in the inventory
    void Inventory::displayBooks() const {
        if (books.empty()) {
            std::cout << "No books in inventory.\n";
            return;
        }
        for (const auto& book : books) {
            std::cout << book << "\n\n";
        }
    }

}
