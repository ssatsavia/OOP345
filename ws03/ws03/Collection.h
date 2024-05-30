//
//  Collection.hpp
//  ws03
//
//  Created by Sage Satsavia on 2024-05-30.
//

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <array>
#include "Book.h"

namespace seneca {

template<typename T, unsigned C>
class Collection {
    std::array<T, C> m_items{};
    unsigned m_size{0};

    static T m_smallestItem;
    static T m_largestItem;

    void setSmallestItem(const T& item) {
        if (item < m_smallestItem) {
            m_smallestItem = item;
        }
    }

    void setLargestItem(const T& item) {
        if (item > m_largestItem) {
            m_largestItem = item;
        }
    }

protected:
    T& operator[](unsigned index) {
        return m_items[index];
    }

    void incrSize() {
        if (m_size < C) {
            ++m_size;
        }
    }

public:
    bool operator+=(const T& item) {
        if (m_size < C) {
            m_items[m_size] = item;
            setSmallestItem(item);
            setLargestItem(item);
            ++m_size;
            return true;
        }
        return false;
    }

    unsigned size() const {
        return m_size;
    }

    unsigned capacity() const {
        return C;
    }

    static T getSmallestItem() {
        return m_smallestItem;
    }

    static T getLargestItem() {
        return m_largestItem;
    }

    void print(std::ostream& os) const {
        for (unsigned i = 0; i < m_size; ++i) {
            os << m_items[i] << " ";
        }
        os << std::endl;
    }
};

// Static member initializations
template<typename T, unsigned C>
T Collection<T, C>::m_smallestItem = 9999;

template<typename T, unsigned C>
T Collection<T, C>::m_largestItem = -9999;

// Specialization for Book type with capacity 10
template<>
Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

template<>
Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

} // namespace seneca

#endif // COLLECTION_H

