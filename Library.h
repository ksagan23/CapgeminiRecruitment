#pragma once
#include "Book.h"

#include <vector>
#include <unordered_map>
#include <tuple>
#include <memory>

class Library {
public:
    Library() = default;

    inline void AddBook(const Book& book) { m_storage.push_back(book); };
    void DeleteBook(const std::string& bookName, const  std::string& authorName);
    void ReportBooksByAuthor(const std::string& authorName);
    void ReportBooksByGenreAndPublisher(const std::string& genre, const std::string& publisher);
    void GetTopPublisher();
    void GetTopGenres();
private:
    std::vector<Book> m_storage;
};



