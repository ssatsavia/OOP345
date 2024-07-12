
#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace seneca {  
    class ConfirmationSender {
        const Reservation** m_reservations{ nullptr };
        size_t m_count{ 0 };

    public:
        // constructor
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender& other);
        ConfirmationSender& operator=(const ConfirmationSender& other);



        // Adding move constructor
        ConfirmationSender(ConfirmationSender&& other) noexcept;  
        // Adding move assignment
        ConfirmationSender& operator=(ConfirmationSender&& other) noexcept;  


        //Destructor
        ~ConfirmationSender();

        //adding the reservation res
        ConfirmationSender& operator+=(const Reservation& res);
        //removing the reservation res from the array 
        ConfirmationSender& operator-=(const Reservation& res);


        //overloading  insertion operator
        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
    };
}

#endif // SENECA_CONFIRMATIONSENDER_H
