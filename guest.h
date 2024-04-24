/* name: jagjit kaur
* id: 156806226
* email:jkaur682@myseneca.ca
* professor: elena bassichilvi
* i had done all the coding by myself  and only copied the code that was given by my professor
*/


#ifndef GUEST_H

#define GUEST_H

namespace seneca
{

    struct Guest
    {
        char* m_firstName;

        char* m_lastName;

        bool m_adult;

    };

    void set(Guest& guest, const char* first, const char* last, int age);

    void print(const Guest& guest);

    void book(Guest& guest);

    void vacate(Guest& guest);


}

// namespace seneca


#endif 
// GUEST_H
