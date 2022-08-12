#include "Book.h"
#include <iostream>

Book::Book(std::string bookName, std::string  authorName,
           std::string genre, const unsigned short int yearOfIssue,
           std::string publisher,
           const unsigned short int nrOfPages):  m_bookName(std::move(bookName)),
                                                 m_authorName(std::move(authorName)),
                                                 m_genre(std::move(genre)),
                                                 m_yearOfIssue(yearOfIssue),
                                                 m_publisher(std::move(publisher)),
                                                 m_nrOfPages(nrOfPages) {}

Book::Book(){
    std::cout << "Insert book name: ";
    std::cin >> std::ws;
    std::getline(std::cin, m_bookName);
    std::cout << "Insert author name: ";
    std::cin >> m_authorName;
    std::cout << "Insert genre: ";
    std::cin >>m_genre;
    std::cout << "Insert year of issue: ";
    std::cin >> m_yearOfIssue;
    std::cout << "Insert publisher: ";
    std::cin >> std::ws;
    std::getline(std::cin, m_publisher);
    std::cout << "Insert nr of pages: ";
    std::cin >> m_nrOfPages;
}

std::ostream& operator<< (std::ostream& os, const Book& book){
    os << "BOOK [TITLE]: " << book.m_bookName << std::endl
       << "\tAuthor name: " << book.m_authorName << std::endl
       << "\tGenre: " << book.m_genre << std::endl
       << "\tYear of issue: " << book.m_yearOfIssue << std::endl
       << "\tPublisher: " << book.m_yearOfIssue << std::endl
       << "\tNr of pages: " << book.m_nrOfPages << std::endl;
    return os;
}