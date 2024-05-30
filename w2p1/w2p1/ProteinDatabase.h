//
//  ProtienDatabase.hpp
//  w2p1
//
//  Created by Sage Satsavia on 2024-05-24.
//

#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H


#include <vector>
#include <string>


namespace seneca {
using namespace std;


    class ProteinDatabase {
    private:
        vector<string> sequences;

    public:
        ProteinDatabase();
        ProteinDatabase(const string& filename);
        size_t size() const;
        string operator[](size_t index) const;
    };
}




#endif /* ProtienDatabase_h */
