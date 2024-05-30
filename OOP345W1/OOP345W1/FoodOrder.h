//
//  FoodOrder.hpp
//  OOP345W1
//
//  Created by Sage Satsavia on 2024-05-15.
//

#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <string>
#include <iostream>

namespace seneca {
    extern double g_taxrate;
    extern double g_dailydiscount;

    class FoodOrder {
    private:
        char customerName[11];
        std::string foodDescription;
        double price;
        bool dailySpecial;
        static int counter;

    public:
        FoodOrder();
        void read(std::istream& is);
        void display() const;
    };
}

#endif

