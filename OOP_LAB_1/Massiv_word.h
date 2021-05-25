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
	}
	Mass_word(const char *word) //����������� � ����� ����������
	{
		if (strlen(word) > LENGTH)
			throw exception("��������� ����� ��������� ������������ �������� ������ ����� � �������. ���������� ������ 15 ��������.");
		if (strlen(word) == 0)
			throw exception("������� ������ ������.");
		
		size = 1;
		strcpy_s(mass[0], word);
	}
	Mass_word(const int size_1, const char word[SIZE][LENGTH]) //����������� � ����� �����������
	{
		if (size_1 <= 0 || size_1 > SIZE)
			throw exception("������ ������������ ������ �������");
		
		size = size_1;
		for (int i = 0; i < size; i++)
		{
			if (strlen(word[i]) > LENGTH)
				throw exception("��������� ����� ��������� ������������ �������� ������ ����� � �������. ���������� ����� 15 ��������.");
			if (strlen(word[i]) == 0)
				throw exception("������� ������ ������.");
			strcpy_s(mass[i], word[i]);
		}
	}

	friend istream & operator >>(istream &in, Mass_word &m);
	friend ostream & operator <<(ostream &out, const Mass_word &m);
	Mass_word & operator +=(const Mass_word &m); // ���������� ��������� +=/���������� ����� � �������
	const int & search(const Mass_word &m); //����� �����
	const char* operator[] (int index) const; // ���������� ��������� []
	Mass_word operator() (char c) const; // ���������� ��������� ()
	Mass_word & sort(); // ����������
	int getSize() const { return size; };
};

#endif