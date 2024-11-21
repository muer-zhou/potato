#include "Book.h"

namespace bookstore {

    // Overload the equality operator (==)
    bool Book::operator==(const Book& other) const {
        return isbn == other.isbn; // Books are equal if they have the same ISBN
    }

    // Overload the stream insertion operator (<<)
    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Title: " << book.title << "\n"
           << "Author: " << book.author << "\n"
           << "ISBN: " << book.isbn << "\n"
           << "Price: $" << book.price;
        return os;
    }

}
