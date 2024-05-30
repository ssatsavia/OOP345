//
//  ProtienDatabase.cpp
//  w2p1
//
//  Created by Sage Satsavia on 2024-05-24.
//



#include "ProteinDatabase.h"
#include <fstream>
#include <iostream>

namespace seneca {

    ProteinDatabase::ProteinDatabase() {}

    ProteinDatabase::ProteinDatabase(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        string sequence;

        // First pass: count the number of protein sequences
        size_t sequenceCount = 0;
        while (getline(file, line)) {
            if (line[0] == '>') {
                sequenceCount++;
            }
        }

        // Allocate memory for the sequences (using vector's reserve)
        sequences.reserve(sequenceCount);

        // Second pass: read and store the protein sequences
        file.clear();
        file.seekg(0);

        while (getline(file, line)) {
            if (line[0] == '>') {
                if (!sequence.empty()) {
                    sequences.push_back(sequence);
                    sequence.clear();
                }
            } else {
                sequence += line;
            }
        }
        if (!sequence.empty()) {
            sequences.push_back(sequence);
        }

        file.close();
    }

    size_t ProteinDatabase::size() const {
        return sequences.size();
    }

    string ProteinDatabase::operator[](size_t index) const {
        if (index < sequences.size()) {
            return sequences[index];
        } else {
            return "";
        }
    }
}

