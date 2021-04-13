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
	Mass_word() //конструктор без параметров
	{
		size = 0;
		for (int i = 0; i < SIZE; i++)  //массив обнул€етс€
			for (int j = 0; j < LENGTH; j++)
				mass[i][j] = ' ';
	}
	Mass_word(const char *word) //конструктор с одним параметром
	{
		if (strlen(word) > LENGTH)
			throw exception("¬веденное слово превышает максимальное значение длинны слова в массиве. ƒопустима€ длинна 15 символов.");
		size = 1;
		for (int i = 0; i < SIZE; i++) //массив обнул€етс€
			for (int j = 0; j < LENGTH; j++)
				mass[i][j] = ' ';

		for (int i = 0; i < size; i++)
			strcpy_s(mass[i], word);
	}
	Mass_word(int size_1, char word[SIZE][LENGTH]) //конструктор с двум€ параметрами
	{
		if (size_1 <= 0)
			throw exception("¬веденн некорректный размер массива");
		
		size = size_1;

		for (int i = 0; i < SIZE; i++) //массив обнул€етс€
			for (int j = 0; j < LENGTH; j++)
				mass[i][j] = ' ';

		for (int i = 0; i < size; i++)
		{
			if (strlen(word[i]) > LENGTH)
				throw exception("¬веденное слово превышает максимальное значение длинны слова в массиве. ƒопустима€ длинна 15 символов.");
			strcpy_s(mass[i], word[i]);
		}
	}

	friend istream & operator >>(istream &in, Mass_word &m);
	friend ostream & operator <<(ostream &out, Mass_word &m);
	Mass_word & operator +=(const Mass_word &m); // ѕерегрузка опреатора +=/ƒобавление слова к массиву
	const int & search(const Mass_word &m); //поиск слова
	const char* operator[] (const int index) const; // перегрузка оператора []
	Mass_word operator() (char c); // перегрузка оператора ()
	Mass_word & sort(); // сортировка
	int getSize() const { return size; };
};

#endif