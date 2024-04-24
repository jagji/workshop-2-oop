#pragma once
/*
*****************************************************************************
						Workshop-2 LAB

Full Name  : jagjit kaur 
Student ID#: 156806226
Email      : jkaur682@myseneca.ca
Section    : NII
Date       : 28/01/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SENECA_ASSESSMENTS_H_
#define SENECA_ASSESSMENTS_H_

#include <iostream>


namespace seneca
{
	const int MAX_LENGTH = 60;

	struct Assessment {
		double* m_mark;
		char* m_title;
	};

	bool read(int& value, FILE* fptr);
	bool read(double& value, FILE* fptr);
	bool read(char* cstr, FILE* fptr);

	bool read(Assessment& asmnt, FILE* fptr);
	void freeMem(Assessment*& aptr, int size);
	int read(Assessment*& aptr, FILE* fptr);
}
#endif 
