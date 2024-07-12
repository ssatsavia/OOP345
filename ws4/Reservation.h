
#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <string>
#include <iostream>

namespace seneca {  

    class Reservation {
        std::string m_reservationId;
        std::string m_name;



        std::string m_email;
        int m_numberOfPeople;
        int m_days;
        int m_hrs;

    public:
        //default constructor
        Reservation();
        //constructor that receives the reservation as a string; 
        Reservation(const std::string& res);
        // Modifier that receives parameters for reservation and updates
        void update(int day, int time);
        //overloading  insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
}

#endif // SENECA_RESERVATION_H
