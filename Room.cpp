/* name: jagjit kaur
* id: 156806226
* email:jkaur682@myseneca.ca
* professor: elena bassichilvi
* i had done all the coding by myself  and only copied the code that was given by my professor
*/


#define _CRT_SECURE_NO_WARNINGS

#include "Room.h"

#include <cstring>

#include <iostream>


namespace seneca
{


    void set(Room& room, int numberOfGuests, const char* roomNumber)
    {
        strncpy(room.m_roomNumber, roomNumber, 5);


        room.m_roomNumber[5] = '\0';


        room.m_noOfGuests = numberOfGuests;


        room.m_guests = new Guest[numberOfGuests];


        for (int i = 0; i < numberOfGuests; ++i)
        
        {
            set(room.m_guests[i], "", "", 0); 
            
            // Initialize each guest

        }

    }


  void print(const Room& room)
  
  {
    // Check if there are no guests and print "Empty Room!"

    if (room.m_noOfGuests == 0 || room.m_guests == nullptr) 
    {
        std::cout << "Empty Room!" << std::endl;

    } else
    {
        std::cout << "Room Number: " << room.m_roomNumber << std::endl;

        for (int i = 0; i < room.m_noOfGuests; ++i)
        {
            std::cout << "    ";

            print(room.m_guests[i]);

        }
    }

}

    void book(Room& room)
    {
        char roomNumber[6];

        int numberOfGuests;

        std::cout << "Room number: ";

        std::cin >> roomNumber;

        std::cout << "Number of guests: ";

        std::cin >> numberOfGuests;

        set(room, numberOfGuests, roomNumber);

        for (int i = 0; i < numberOfGuests; ++i)
        {
            std::cout << i + 1 << ":" << std::endl;


            book(room.m_guests[i]);

        }

    }


    void vacate(Room& room) 
    
    {
        for (int i = 0; i < room.m_noOfGuests; ++i)
        
        {
            vacate(room.m_guests[i]);


        }
        delete[] room.m_guests;


        room.m_guests = nullptr;

        room.m_noOfGuests = 0;

    }

}
