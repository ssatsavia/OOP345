

#define _CRT_SECURE_NO_WARNINGS
#include "Restaurant.h"

namespace seneca {
    //constructor that receives as a parameter an array of pointers to objects of type Reservation

    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {


        m_reservations = new Reservation * [cnt];
        for (size_t i = 0; i < cnt; ++i) {


            m_reservations[i] = new Reservation(*reservations[i]);
        }
        m_count = cnt;



    }
    Restaurant::Restaurant(const Restaurant& other) {
        *this = other;
    }
    Restaurant& Restaurant::operator=(const Restaurant& other) {
        if (this != &other) {
            for (size_t i = 0; i < m_count; ++i) {
                delete m_reservations[i];
            }
            delete[] m_reservations;




            m_reservations = new Reservation * [other.m_count];
            for (size_t i = 0; i < other.m_count; ++i) {
                m_reservations[i] = new Reservation(*other.m_reservations[i]);
            }
            m_count = other.m_count;
        }
        return *this;
    }

    // Added move constructor
    Restaurant::Restaurant(Restaurant&& other) noexcept {
        m_reservations = other.m_reservations;
        m_count = other.m_count;
        other.m_reservations = nullptr;
        other.m_count = 0;
    }

    // Added move assignment
    Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < m_count; ++i) {
                delete m_reservations[i];
            }
            delete[] m_reservations;

            m_reservations = other.m_reservations;
            m_count = other.m_count;
            other.m_reservations = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    // destructor
    Restaurant::~Restaurant() {
        for (size_t i = 0; i < m_count; ++i) {
            delete m_reservations[i];
        }
        delete[] m_reservations;
    }

    //A query that returns the number of reservations in the system

    size_t Restaurant::size() const {
        return m_count;
    }
    //overloading  insertion operator

    std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
        static size_t CALL_CNT = 0;
        os << "--------------------------\n";
        os << "Fancy Restaurant (" << ++CALL_CNT << ")\n";
        os << "--------------------------\n";

        if (restaurant.size() == 0) {
            os << "This restaurant is empty!\n";
        }
        else {
            for (size_t i = 0; i < restaurant.size(); ++i) {
                os << *restaurant.m_reservations[i];
            }
        }

        os << "--------------------------\n";
        return os;
    }
}
