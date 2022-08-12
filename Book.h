#pragma once

#include <string>
#include <utility>
#include <iostream>

class Book{
public:
    Book(std::string bookName, std::string authorName,
         std::string genre, unsigned short int yearOfIssue,
         std::string publisher,
         unsigned short int nrOfPages);
    Book();
    ~Book() = default;

    inline std::string GetBookName() const { return m_bookName; };
    inline std::string GetAuthorName() const { return m_authorName; };
    inline std::string GetGenre() const { return m_genre; };
    inline std::string GetPublisher() const { return m_publisher; };

    friend std::ostream& operator<< (std::ostream& os, const Book& book);
private:
    std::string m_bookName;
    std::string m_authorName;
    std::string m_genre;
    short int m_yearOfIssue;
    std::string m_publisher;
    unsigned short int m_nrOfPages;
};