//
//  FoodOrder.cpp
//  oopw1_p2
//
//  Created by Sage Satsavia on 2024-05-19.
//

#include "FoodOrder.h"
#include <iomanip>
#include <cstring>

using namespace std;

namespace seneca {
    double g_taxrate = 0.0;
    double g_dailydiscount = 0.0;

    int FoodOrder::counter = 0;

    FoodOrder::FoodOrder() : price(0.0), dailySpecial(false) {
        customerName[0] = '\0';
    }

    void FoodOrder::read(istream& is) {
        if (is) {
            char special;
            is.getline(customerName, 11, ',');
            getline(is, foodDescription, ',');
            is >> price;
            is.ignore(); // to skip the comma
            is >> special;
            is.ignore(); // to skip the newline
            dailySpecial = (special == 'Y');
        }
    }

    void FoodOrder::display() const {
        cout << setw(2) << left << ++counter << ". ";
        if (customerName[0] != '\0') {
            cout << setw(10) << left << customerName << "|"
                 << setw(25) << left << foodDescription << "|"
                 << setw(12) << left << fixed << setprecision(2) << (price * (1 + g_taxrate)) << "|";
            if (dailySpecial) {
                cout << setw(13) << right << fixed << setprecision(2) << (price * (1 + g_taxrate) - g_dailydiscount);
            }
            cout << endl;
        } else {
            cout << "No Order" << endl;
        }
    }
}
