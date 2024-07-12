
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <algorithm>
#include "Reservation.h"

namespace seneca {
    //default constructor
    Reservation::Reservation() {}



    //constructor that receives the reservation as a string; 
    Reservation::Reservation(const std::string& res) {
        size_t start = 0, end = 0;


        // Extract reservation ID
        end = res.find(':');
        m_reservationId = res.substr(start, end);
        m_reservationId.erase(0, m_reservationId.find_first_not_of(" "));


        m_reservationId.erase(m_reservationId.find_last_not_of(" ") + 1);
        start = end + 1;

        // Extracting name
        end = res.find(',', start);
        m_name = res.substr(start, end - start);
        m_name.erase(0, m_name.find_first_not_of(" "));
        m_name.erase(m_name.find_last_not_of(" ") + 1);
        start = end + 1;

        // Extracting email
        end = res.find(',', start);
        m_email = res.substr(start, end - start);
        m_email.erase(0, m_email.find_first_not_of(" "));
        m_email.erase(m_email.find_last_not_of(" ") + 1);
        start = end + 1;

        // Extract number of people
        end = res.find(',', start);
        m_numberOfPeople = std::stoi(res.substr(start, end - start));
        start = end + 1;

        // Extracting day
        end = res.find(',', start);
        m_days = std::stoi(res.substr(start, end - start));
        start = end + 1;

        // Extracting hour
        m_hrs = std::stoi(res.substr(start));
    }

    // Modifier that receives parameters for reservation and updates

    void Reservation::update(int day, int time) {
        m_days = day;
        m_hrs = time;
    }

    //overloading  insertion operator
    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        os << "Reservation " << std::setw(10) << std::right << res.m_reservationId << ": "
            << std::setw(20) << std::right << res.m_name << "  "
            << std::left << std::setw(20) << "<" + res.m_email + ">"
            << "    ";

        // Adjust the string based on the number of people
        std::string personString = (res.m_numberOfPeople == 1) ? "person" : "people";

        if (res.m_hrs >= 6 && res.m_hrs <= 9) {
            os << "Breakfast";
        }
        else if (res.m_hrs >= 11 && res.m_hrs <= 15) {
            os << "Lunch";
        }
        else if (res.m_hrs >= 17 && res.m_hrs <= 21) {
            os << "Dinner";
        }
        else {
            os << "Drinks";
        }

        os << " on day " << res.m_days << " @ " << res.m_hrs << ":00"
            << " for " << res.m_numberOfPeople << " " << personString << "." << std::endl;

        return os;
    }
}
