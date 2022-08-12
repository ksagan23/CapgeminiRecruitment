#include "Library.h"
#include <iostream>
#include <map>
#include <algorithm>

void Library::DeleteBook(const std::string& bookName, const  std::string& authorName) {
    // we look for book with certain name and by certain author, and remove it
    m_storage.erase(std::find_if(m_storage.begin(), m_storage.end(), [&](auto &book) {
        return book.GetAuthorName() == authorName && book.GetBookName() == bookName;
    }));
}

void Library::ReportBooksByAuthor(const std::string &authorName) {
    // we loop through the storage and print those books, which author corresponds with the one, which was
    // given by the user
    std::for_each(m_storage.begin(), m_storage.end(), [&authorName](const auto& book){
        if(book.GetAuthorName() == authorName){
            std::cout << book << std::endl;
        }
    });
}

void Library::ReportBooksByGenreAndPublisher(const std::string& genre, const std::string& publisher){
    std::for_each(m_storage.begin(), m_storage.end(), [&](const auto& book){
        if(book.GetGenre() == genre && book.GetPublisher() == publisher){
            std::cout << book << std::endl;
        }
    });
}

void Library::GetTopPublisher() {
    std::vector<std::string> publishers;
    // first, we get unique publishers
    for(const auto& book : m_storage){
        if(std::find(publishers.begin(), publishers.end(), book.GetPublisher()) == publishers.end()){
            publishers.push_back((book.GetPublisher()));
        }
    }
    std::vector<std::pair<std::string, size_t>> occurences;
    // then, we count nr of occurences of a certain publisher
    for(const auto& publisher : publishers){
        size_t publishers_books = std::count_if(m_storage.begin(), m_storage.end(), [&](const auto& book){
                                  return book.GetPublisher() == publisher; });
        occurences.push_back({publisher, publishers_books});
    }
    auto publisher = std::max_element(occurences.begin(), occurences.end(),[](const auto& p1, const auto& p2) {return p1.second < p2.second; });
    std::cout << "Top publisher: " << publisher->first << std::endl;
}

void Library::GetTopGenres(){
    std::vector<std::string> genres;
    // similarly to function above, first we get all unique genres
    for(const auto& book : m_storage){
        if(std::find(genres.begin(), genres.end(), book.GetGenre()) == genres.end()){
            genres.push_back(book.GetGenre());
        }
    }
    std::vector<std::pair<std::string, size_t>> occurences;
    // then, we count nr of occurences of certian genre
    for(const auto & genre : genres){
        size_t nr_of_books = std::count_if(m_storage.begin(), m_storage.end(), [&](const auto &book){
            return book.GetGenre() == genre;
        });
        occurences.push_back({genre, nr_of_books});
    }
    // then, we sort vector in descending order
    std::sort(occurences.begin(), occurences.end(), [](const auto& p1, const auto& p2){ return p1.second < p2.second; });
    int size = occurences.size();
    // and finally we print top 3 genres
    for(int i = 0; i < std::min(size, 3); ++i){
        std::cout << i << ". " << occurences[i].first << std::endl;
    }
}