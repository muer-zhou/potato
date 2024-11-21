#include <iostream>
#include "Inventory.h"

using namespace std;
using namespace bookstore;

int main() {
    Inventory inventory;

    // Sample interaction
    while (true) {
        cout << "\nBookstore Inventory System\n";
        cout << "1. Add a Book\n";
        cout << "2. Find a Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        if (choice == 1) {
            // Add a book
            Book book;
            cout << "Enter book title: ";
            getline(cin, book.title);
            cout << "Enter book author: ";
            getline(cin, book.author);
            cout << "Enter book ISBN: ";
            getline(cin, book.isbn);
            cout << "Enter book price: ";
            cin >> book.price;
            cin.ignore(); // Clear the input buffer

            inventory.addBook(book);
            cout << "Book added successfully!\n";

        } else if (choice == 2) {
            // Find a book
            string isbn;
            cout << "Enter the ISBN of the book to find: ";
            getline(cin, isbn);

            Book* book = inventory.findBook(isbn);
            if (book) {
                cout << "Book found:\n" << *book << "\n";
            } else {
                cout << "Book not found.\n";
            }

        } else if (choice == 3) {
            // Display all books
            cout << "Books in Inventory:\n";
            inventory.displayBooks();

        } else if (choice == 4) {
            // Exit
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
