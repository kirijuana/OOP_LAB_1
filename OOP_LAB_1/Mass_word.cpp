#include "pch.h"
#include "Massiv_word.h"


istream & operator >>(istream &in, Mass_word &m) {
	for (int i = 0; i < m.size; i++)
	{
		in >> m.mass[i];
		if (strlen(m.mass[i]) >= LENGTH)
			throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
		for (int j = 0; j < i; j++)
		{
			if (!strcmp(m.mass[i], m.mass[j]))
				throw exception("Массив не был заполнен, поскольку вы ввели повторяющееся слово. Заполните массив снова.");
		}
	}
	return in;
}	

ostream & operator <<(ostream &out, Mass_word &m)
{
	if (m.size == 0)
		throw exception("Массив пуст.");
	else
	{ 
		out << "Слова: " << endl;
		for (int i = 0; i < m.size; i++)
		{
			out << i + 1 << ") " << m.mass[i] << endl;
		}
	}

	return out;
}
Mass_word & Mass_word::operator +=(char m[LENGTH]) // Перегрузка опреатора +=/Добавление слова к массиву
{
	size = size + 1;
	for (int j = 0; j < LENGTH; j++)
	{
		if (j < sizeof(m) + 1)
			mass[size - 1][j] = m[j];
		else
			mass[size - 1][j] = ' ';

	}
	return *this;
}

const Mass_word & Mass_word::search(const char *m) //поиск слова
{
	if (strlen(m) > LENGTH)
		throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
	int check = 0; // переменная для проверки идентичности 2-х слов
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (mass[i][j] == m[j])
				check++;
			else
			{
				check = 0;
				break;
			}

			if (check == strlen(m))
			{
				cout << "Слово: " << "<<" << m << ">>" << " " << "есть. Его позиция: №" << i + 1 << endl;
				check = -1;
				break;
			}

		}
		if (check == -1)
			break;
		check = 0;
	}
	if (check != -1)
	{
		cout << "Слова: " << m << " " << "нет." << endl;
	}
	return *this;
}

Mass_word & Mass_word::operator() (char c) // перегрузка оператора ()
{
	char mass1[SIZE][LENGTH] = { "Hello", "Buy", "From", "Russia", "russia", "Rainbow", "Germany", "great", "Britan", "based" };
	int k = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (((int)mass1[i][0] - (int)c) % 32 == 0 || mass1[i][0] == c)
		{
			for (int j = 0; j < LENGTH; j++)
			{
				mass[k][j] = mass1[i][j];
			}
			k++;
		}
	}
	size = k;
	return *this;
}

Mass_word & Mass_word::sort() // Метод сортировка
{
	if (size == 0)
	{
		throw exception("Массив пуст. Сортировка невозможна.");
	}
	if (size == 1)
	{
		throw exception("Массив содержит 1 элемент. Сортировка невозможна.");
	}
	char tmp[LENGTH];
	for (int j = 1; j < size; j++)
		for (int i = 0; i < size - j; i++)
		{
			if (strcmp(mass[i + 1], mass[i]) < 0)
			{
				for (int k = 0; k < LENGTH; k++)
					tmp[k] = mass[i][k];
				for (int k = 0; k < LENGTH; k++)
					mass[i][k] = mass[i + 1][k];
				for (int k = 0; k < LENGTH; k++)
					mass[i + 1][k] = tmp[k];
			}
		}
	return *this;
}

char* Mass_word::operator[] (const int index) // перегрузка оператора []
{
	if (index > SIZE)
		throw exception("Значение индекса превышает размерность массива. Введите корректное значение.");
	return mass[index];
}