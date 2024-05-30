//
//  OrderedCollectiion.hpp
//  ws03p2
//
//  Created by Sage Satsavia on 2024-05-30.
//

#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace seneca {

template<typename T>
class OrderedCollection : public Collection<T, 100> {
public:
    bool operator+=(const T& item) {
        if (this->m_size < this->m_items.size()) {
            // Find the correct position to insert the item
            auto pos = std::find_if(this->m_items.begin(), this->m_items.begin() + this->m_size,
                                    [&](const T& currentItem) { return item < currentItem; });

            // Calculate the index
            auto index = std::distance(this->m_items.begin(), pos);

            // Shift elements to the right
            for (unsigned i = this->m_size; i > index; --i) {
                this->m_items[i] = this->m_items[i - 1];
            }

            // Insert the new item
            this->m_items[index] = item;

            ++this->m_size;
            this->setSmallestItem(item);
            this->setLargestItem(item);
            return true;
        }
        return false;
    }

    void print(std::ostream& os) const {
        for (unsigned i = 0; i < this->m_size; ++i) {
            os << this->m_items[i] << " ";
        }
        os << std::endl;
    }
};

} // namespace seneca

#endif // ORDEREDCOLLECTION_H

