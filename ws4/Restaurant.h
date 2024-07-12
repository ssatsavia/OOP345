
#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace seneca {  
    class Restaurant {
        Reservation** m_reservations{ nullptr };
        size_t m_count{ 0 };

    public:
        //constructor that receives as a parameter an array of pointers to objects of type Reservation

        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant& other);
        Restaurant& operator=(const Restaurant& other);


        //  move constructor
        Restaurant(Restaurant&& other) noexcept; 
        //  move assignment
        Restaurant& operator=(Restaurant&& other) noexcept; 
        // destructor
        ~Restaurant();

        //A query that returns the number of reservations in the system
        size_t size() const;
        //overloading insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
    };
}

#endif // SENECA_RESTAURANT_H
