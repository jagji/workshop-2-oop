/* name: jagjit kaur
* id: 156806226
* email:jkaur682@myseneca.ca
* professor: elena bassichilvi
* i had done all the coding by myself  and only copied the code that was given by my professor
*/


#ifndef ROOM_H

#define ROOM_H

#include "Guest.h"  


// Make sure Guest.h is in the same directory or include path



namespace seneca 

{

    struct Room
    
    {
        char m_roomNumber[6];

        int m_noOfGuests;

        Guest* m_guests;
    };

    void set(Room& room, int numberOfGuests, const char* roomNumber);

    void print(const Room& room);

    void book(Room& room);

    void vacate(Room& room);


} 
// namespace seneca



#endif 

// ROOM_H
