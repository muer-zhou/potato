#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <vector>

namespace bookstore {

    class Inventory {
    private:
        std::vector<Book> books;

    public:
        // Add a book to the inventory
        void addBook(const Book& book);

        // Find a book by its ISBN
        Book* findBook(const std::string& isbn);

        // Display all books in the inventory
        void displayBooks() const;
    };

}

#endif // INVENTORY_H
