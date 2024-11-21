#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

namespace bookstore {

    struct Book {
        std::string title;
        std::string author;
        std::string isbn;
        double price;

        // Overload the equality operator (==)
        bool operator==(const Book& other) const;

        // Overload the stream insertion operator (<<)
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
    };

}

#endif // BOOK_H
