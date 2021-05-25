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
	}
	Mass_word(const char *word) //конструктор с одним параметром
	{
		if (strlen(word) > LENGTH)
			throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
		if (strlen(word) == 0)
			throw exception("Введена пустая строка.");
		
		size = 1;
		strcpy_s(mass[0], word);
	}
	Mass_word(const int size_1, const char word[SIZE][LENGTH]) //конструктор с двумя параметрами
	{
		if (size_1 <= 0 || size_1 > SIZE)
			throw exception("Введен некорректный размер массива");
		
		size = size_1;
		for (int i = 0; i < size; i++)
		{
			if (strlen(word[i]) > LENGTH)
				throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длина 15 символов.");
			if (strlen(word[i]) == 0)
				throw exception("Введена пустая строка.");
			strcpy_s(mass[i], word[i]);
		}
	}

	friend istream & operator >>(istream &in, Mass_word &m);
	friend ostream & operator <<(ostream &out, const Mass_word &m);
	Mass_word & operator +=(const Mass_word &m); // Перегрузка опреатора +=/Добавление слова к массиву
	const int & search(const Mass_word &m); //поиск слова
	const char* operator[] (int index) const; // перегрузка оператора []
	Mass_word operator() (char c) const; // перегрузка оператора ()
	Mass_word & sort(); // сортировка
	int getSize() const { return size; };
};

#endif