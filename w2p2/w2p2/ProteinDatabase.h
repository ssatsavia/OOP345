//
//  ProteinDatabase.hpp
//  w2p2
//
//  Created by Sage Satsavia on 2024-05-24.
//

#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <string>
#include <vector>

namespace seneca {
using namespace std;

    class ProteinDatabase {
        vector<string> sequences;

    public:
        ProteinDatabase();
        ProteinDatabase(const string& filename);
        ProteinDatabase(const ProteinDatabase& other);
        ProteinDatabase(ProteinDatabase&& other) noexcept;
        ProteinDatabase& operator=(const ProteinDatabase& other);
        ProteinDatabase& operator=(ProteinDatabase&& other) noexcept;
        ~ProteinDatabase();

        size_t size() const;
        string operator[](size_t index) const;
    };
}

#endif // SENECA_PROTEINDATABASE_H



