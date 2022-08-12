#include <iostream>
#include <optional>
#include "Book.h"
#include "Library.h"

enum class ReportsAction{
    BY_AUTHOR = 1,
    BY_GENRE_AND_PUBLISHER,
    BY_QUANTITY,
    BY_POPULARITY
};


int main() {
    Library myLibrary;

    unsigned int action {};

    while(action != 4) {
        std::cout << "Welcome to library, choose action: " << std::endl
                  << "\t1. Add Book" << std::endl
                  << "\t2. Delete Book" << std::endl
                  << "\t3. Show Reports" << std::endl
                  << "\t4. Exit" << std::endl;
        std::cin >> action;
        if (action == 1) {
            Book tmpBook;
            myLibrary.AddBook(tmpBook);
        } else if (action == 2) {
            std::string author;
            std::string title;
            std::cout << "Insert author name: ";
            std::cin >> author;
            std::cout << "Insert book title: ";
            std::cin >> title;
            myLibrary.DeleteBook(author, title);
        } else if (action == 3) {
            unsigned int reportsAction;
            std::string author;
            std::string genre;
            std::string publisher;
            std::cout << "Choose reports:" << std::endl
                      << "\t1. Show all books by the same author" << std::endl
                      << "\t2. Show all books of a given genre and publisher" << std::endl
                      << "\t3. Show the name of the publisher with the maximum quantity of the books" << std::endl
                      << "\t4. Show TOP-3 genres (popularity is determined by the number of books in the genre)"
                      << std::endl;
            std::cin >> reportsAction;
            switch (static_cast<ReportsAction>(reportsAction)) {
                case ReportsAction::BY_AUTHOR:
                    std::cout << "Insert author name:";
                    std::cin >> author;
                    myLibrary.ReportBooksByAuthor(author);
                    break;
                case ReportsAction::BY_GENRE_AND_PUBLISHER:
                    std::cout << "Insert genre: ";
                    std::cin >> genre;
                    std::cout << "Insert publisher: ";
                    std::cin >> publisher;
                    myLibrary.ReportBooksByGenreAndPublisher(genre, publisher);
                    break;
                case ReportsAction::BY_QUANTITY:
                    myLibrary.GetTopPublisher();
                    break;
                case ReportsAction::BY_POPULARITY:
                    myLibrary.GetTopGenres();
                    break;
            }
        }
    }
}
