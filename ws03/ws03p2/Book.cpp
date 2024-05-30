//
//  Book.cpp
//  ws03p2
//
//  Created by Sage Satsavia on 2024-05-30.
//

#include "Book.h"
#include <iomanip>

namespace seneca {

Book::Book() : m_title(""), m_numChapters(0), m_numPages(0) {}

Book::Book(const std::string& title, unsigned nChapters, unsigned nPages)
    : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}

bool Book::isValid() const {
    return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
}

std::ostream& Book::print(std::ostream& os) const {
    if (isValid()) {
        os << std::right << std::setw(56) << m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages)
           << " | " << std::left << std::setw(15) << "(" + std::to_string(m_numPages / m_numChapters) + ")";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Book& bk) {
    return bk.print(os);
}

std::string Book::getTitle() const {
    return m_title;
}

unsigned Book::getNumChapters() const {
    return m_numChapters;
}

unsigned Book::getNumPages() const {
    return m_numPages;
}

double Book::getPagesPerChapter() const {
    return static_cast<double>(m_numPages) / m_numChapters;
}

bool Book::operator<(const Book& other) const {
    return this->getPagesPerChapter() < other.getPagesPerChapter();
}

bool Book::operator>(const Book& other) const {
    return this->getPagesPerChapter() > other.getPagesPerChapter();
}

} // namespace seneca

