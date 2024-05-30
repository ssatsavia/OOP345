//
//  main.cpp
//  OOP345W1
//
//  Created by Sage Satsavia on 2024-05-15.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FoodOrder.h"

#ifndef SENECA_FOODORDER_H
    #error "The header guard for 'FoodOrder.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

/* input file format: a comma-separated set of fields with a consistent format of
<Order Tag>,<Customer Name>,<Order Description>,<Price>,<Daily Special Status>

<Order Tag> can be one of:
    I - In house order
    D - Delivery order

<Daily Special Status> can be one of:
    Y - Is a daily special
    N - Is not a daily special
*/

// Prototype for the main function to accept command line arguments
int main(int argc, char* argv[]) {
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";

    // Print the command line arguments
    for (int i = 0; i < argc; ++i) {
        std::cout << i + 1 << ": " << argv[i] << std::endl;
    }
    std::cout << "--------------------------\n\n";

    // Arrays to keep a record of the In House and Delivery orders separately
    seneca::FoodOrder recordedDeliveryOrders[6];
    // Counter to keep track of how many delivery orders recorded
    size_t numDeliveries = 0;

    seneca::FoodOrder currentOrder;

    // Process each day's orders
    for (int day = 1; day < argc; ++day) {
        // Change rates depending on the day
        if (day == 1) {
            seneca::g_taxrate = 0.13;
            seneca::g_dailydiscount = 1.15;
        } else {
            seneca::g_taxrate = 0.14;
            seneca::g_dailydiscount = 1.20;
        }

        std::cout << "--------------------\n";
        std::cout << "    Day " << day << '\n';
        std::cout << "--------------------\n";
        std::cout << "Name          |Order Description        |Price w/Tax |Special Price" << std::endl;

        std::ifstream in(argv[day]);
        if (!in.is_open()) {
            std::cout << "Cannot open file [" << argv[day] << "]. Ignoring it!\n";
            continue; // Proceed to the next file
        }

        char ordertag = '\0';

        // Loop through each order in the file
        while (in >> ordertag) {
            // Skip the delimiter
            in.ignore();

            // Read the rest of the data as a FoodOrder
            currentOrder.read(in);

            // Handle the in house and delivery orders differently
            if (ordertag == 'I') {
                seneca::FoodOrder copy = currentOrder;
                copy.display();
            } else if (ordertag == 'D') { // Add the delivery orders to the record
                recordedDeliveryOrders[numDeliveries++] = currentOrder;
                currentOrder.display();
            }
        }
    }

    // Print the recorded delivery orders
    std::cout << "--------------------\n";
    std::cout << "Recorded Delivery Food Orders\n";
    std::cout << "--------------------\n";
    std::cout << "Name          |Order Description        |Price w/Tax |Special Price" << std::endl;
    for (size_t i = 0; i < numDeliveries; ++i) {
        recordedDeliveryOrders[i].display();
    }
    std::cout << "--------------------\n";

    return cout;
}
