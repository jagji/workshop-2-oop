
/* name: jagjit kaur
* id: 156806226
* email:jkaur682@myseneca.ca
* professor: elena bassichilvi
* i had done all the coding by myself  and only copied the code that was given by my professor
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Guest.h"

#include <cstring>

#include <iostream>


namespace seneca 
{

    void set(Guest& guest, const char* first, const char* last, int age)
    
    {
        // Validate input and allocate memory for names


        if (first && *first && last && *last)
        
        {
            guest.m_firstName = new char[strlen(first) + 1];

            strcpy(guest.m_firstName, first);

            guest.m_lastName = new char[strlen(last) + 1];

            strcpy(guest.m_lastName, last);

            guest.m_adult = age >= 18;
        }

        else
        {
            guest.m_firstName = guest.m_lastName = nullptr;

            guest.m_adult = false;

        }
    }

    void print(const Guest& guest)
    {
        if (guest.m_firstName && guest.m_lastName) 
        {
            std::cout << guest.m_firstName << " " << guest.m_lastName;

            if (!guest.m_adult) std::cout << "(Child)";

        }
        else 
        {
            std::cout << "Vacated!";

        }
        std::cout << std::endl;

    }

    void book(Guest& guest)
    {
        char first[100], last[100];

        int age;

        std::cout << "Name: ";

        std::cin >> first;

        std::cout << "Lastname: ";

        std::cin >> last;


        std::cout << "Age: ";

        std::cin >> age;

        set(guest, first, last, age);

    }

    void vacate(Guest& guest) 
    {
        delete[] guest.m_firstName;

        delete[] guest.m_lastName;

        guest.m_firstName = guest.m_lastName = nullptr;

   
    }
}
