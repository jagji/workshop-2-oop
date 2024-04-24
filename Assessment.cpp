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


#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"
#include <cstring> //ADDED Later

namespace seneca
{
	bool read(int& value, FILE* fptr)
	{
		return (fscanf(fptr, "%d\n", &value) == 1);
	}

	bool read(double& value, FILE* fptr)
	{
		return (fscanf(fptr, "%lf\n", &value) == 1);
	}

	bool read(char* cstr, FILE* fptr)
	{
		return (fscanf(fptr, ",%60[^\n]\n", cstr) == 1);
	}

	bool read(Assessment& asmnt, FILE* fptr)
	{
		double tempDouble;
		char tempCString[MAX_LENGTH + 1] = { '\0' };
		bool success;
		int returnValue = 0;
		returnValue = int(read(tempDouble, fptr));
		returnValue += int(read(tempCString, fptr));

		if (returnValue == 2)
		{
			asmnt.m_mark = new double;
			asmnt.m_title = new char[strlen(tempCString) + 1];

			*asmnt.m_mark = tempDouble;
			strcpy(asmnt.m_title, tempCString);

			success = true;
		}
		else
		{
			success = false;
		}
		return success;
	}

	void freeMem(Assessment*& aptr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete aptr[i].m_mark;
			delete[] aptr[i].m_title;
		}
		delete[] aptr; // Deallocation of the array
	}

	int read(Assessment*& aptr, FILE* fptr)
	{
		// Variable declarations
		int totalRecords, i;
		bool returnValue = true;
		bool success;
		int count = 0;

		// Reads the first integer telling the totalRecords in that file
		success = read(totalRecords, fptr);

		// If condition: If the above read is successful, execute the block of statements
		if (success)
		{
			// Dynmanically Allocate memory for the array of structure using its pointer 
			aptr = new Assessment[totalRecords];

			for (i = 0; i < totalRecords && returnValue; i++)
			{
				returnValue = read(aptr[i], fptr);
				if (returnValue)
				{
					count++;
				}
			}
		}

		if (count != totalRecords)
		{
			freeMem(aptr, count);
			return 0;
		}
		else
		{
			return count;
		}
	}
}
