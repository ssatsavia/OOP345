//
//  Book.h
//  ws03
//
//  Created by Sage Satsavia on 2024-05-30.
//

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>

namespace seneca {

class Book {
    std::string m_title{};
    unsigned m_numChapters{};
    unsigned m_numPages{};

public:
    Book();
    Book(const std::string& title, unsigned nChapters, unsigned nPages);

    bool isValid() const;
    std::ostream& print(std::ostream& os) const;

    // Additional member functions needed for Collection
    std::string getTitle() const;
    unsigned getNumChapters() const;
    unsigned getNumPages() const;
    double getPagesPerChapter() const;
};

std::ostream& operator<<(std::ostream& os, const Book& bk);

} // namespace seneca

#endif // BOOK_H

