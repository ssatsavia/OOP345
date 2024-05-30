//
//  ProteinDatabase.cpp
//  w2p2
//
//  Created by Sage Satsavia on 2024-05-24.
//


#include "ProteinDatabase.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace seneca {
using namespace std;


    ProteinDatabase::ProteinDatabase() {}

    ProteinDatabase::ProteinDatabase(const string& filename) {
        ifstream file(filename);
        if (!file) {
            throw runtime_error("Cannot open file");
        }

        string line;
        stringstream sequence;
        while (getline(file, line)) {
            if (line.empty()) continue;

            if (line[0] == '>') {
                if (sequence.tellp() > 0) {
                    sequences.push_back(sequence.str());
                    sequence.str(string());
                }
            } else {
                sequence << line;
            }
        }
        if (sequence.tellp() > 0) {
            sequences.push_back(sequence.str());
        }
    }

    ProteinDatabase::ProteinDatabase(const ProteinDatabase& other)
        : sequences(other.sequences) {}

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& other) noexcept
: sequences(std::move(other.sequences)) {}

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& other) {
        if (this != &other) {
            sequences = other.sequences;
        }
        return *this;
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& other) noexcept {
        if (this != &other) {
            sequences = std::move(other.sequences);
        }
        return *this;
    }

    ProteinDatabase::~ProteinDatabase() {}

    size_t ProteinDatabase::size() const {
        return sequences.size();
    }

   string ProteinDatabase::operator[](size_t index) const {
        if (index < sequences.size()) {
            return sequences[index];
        }
        return "";
    }
}
