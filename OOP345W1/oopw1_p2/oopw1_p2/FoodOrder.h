//
//  FoodOrder.hpp
//  oopw1_p2
//
//  Created by Sage Satsavia on 2024-05-19.
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
