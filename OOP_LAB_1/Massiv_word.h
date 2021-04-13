#ifndef _MASS_WORD_
#define _MASS_WORD_

#include <iostream>
#include <string>
#include "constants.h"

using namespace std;
using namespace constants;

class Mass_word 
{
private:
	int size = 0;
	char mass[SIZE][LENGTH];
public:
	Mass_word() //����������� ��� ����������
	{
		size = 0;
		for (int i = 0; i < SIZE; i++)  //������ ����������
			for (int j = 0; j < LENGTH; j++)
				mass[i][j] = ' ';
	}
	Mass_word(const char *word) //����������� � ����� ����������
	{
		if (strlen(word) > LENGTH)
			throw exception("��������� ����� ��������� ������������ �������� ������ ����� � �������. ���������� ������ 15 ��������.");
		size = 1;
		for (int i = 0; i < SIZE; i++) //������ ����������
			for (int j = 0; j < LENGTH; j++)
				mass[i][j] = ' ';

		for (int i = 0; i < size; i++)
			strcpy_s(mass[i], word);
	}
	Mass_word(int size_1, char word[SIZE][LENGTH]) //����������� � ����� �����������
	{
		if (size_1 <= 0)
			throw exception("������� ������������ ������ �������");
		
		size = size_1;

		for (int i = 0; i < SIZE; i++) //������ ����������
			for (int j = 0; j < LENGTH; j++)
				mass[i][j] = ' ';

		for (int i = 0; i < size; i++)
		{
			if (strlen(word[i]) > LENGTH)
				throw exception("��������� ����� ��������� ������������ �������� ������ ����� � �������. ���������� ������ 15 ��������.");
			strcpy_s(mass[i], word[i]);
		}
	}

	friend istream & operator >>(istream &in, Mass_word &m);
	friend ostream & operator <<(ostream &out, Mass_word &m);
	Mass_word & operator +=(const Mass_word &m); // ���������� ��������� +=/���������� ����� � �������
	const int & search(const Mass_word &m); //����� �����
	const char* operator[] (const int index) const; // ���������� ��������� []
	Mass_word operator() (char c); // ���������� ��������� ()
	Mass_word & sort(); // ����������
	int getSize() const { return size; };
};

#endif