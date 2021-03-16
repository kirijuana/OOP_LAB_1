#ifndef _MASS_WORD_
#define _MASS_WORD_

#include <string.h>
#include <cstring>
#include <iostream>
#include <string>
#include "constants.h"

using namespace std;
using namespace constants;

class Mass_word 
{
private:
	int size = SIZE;
	char mass[SIZE][LENGTH];
public:
	Mass_word() //����������� ��� ����������
	{
		for (int i = 0; i < SIZE; i++) 
		{
			for (int j = 0; j < LENGTH; j++)
			{
				mass[i][j] = ' ';
			}
		}
	}
	Mass_word(const char *word) //����������� � ����� ����������
	{
		size = 1;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < LENGTH; j++)
			{
				if (j < sizeof(word))
					mass[i][j] = word[j];
				else
					mass[i][j] = ' ';
			}
		}
	}
	Mass_word(int size_1, char word[SIZE][LENGTH]) //����������� � ����� �����������
	{
		size = size_1;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < LENGTH; j++)
			{
				if (j < sizeof(word[i]))
					mass[i][j] = word[i][j];
				else
					mass[i][j] = ' ';
				
			}
		}
	}
	
	friend istream & operator >>(istream &in, Mass_word &m);
	friend ostream & operator <<(ostream &out, Mass_word &m);
	Mass_word & operator +=(const char *m); // ���������� ��������� +=/���������� ����� � �������
	Mass_word & search(const char *m); //����� �����
	char* operator[] (const int index); // ���������� ��������� []
	Mass_word & operator() (char c); // ���������� ��������� ()
	const Mass_word & sort(); // ����������
};

#endif