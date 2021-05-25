#include "pch.h"
#include "Massiv_word.h"
#include <boost/algorithm/string.hpp>    


using namespace boost::algorithm;

istream & operator >>(istream &in, Mass_word &m) //передедлал ввод
{		
	char str[LENGTH] = " ";
	Mass_word temp = Mass_word(str);
	
	in >> temp.size;
	
	if (m.size > SIZE || m.size < 0)
	{
		in.setstate(ios_base::failbit);
		return in;
	}	

	for (int i = 0; i < m.size; i++)
	{
		in >> str;
		
		if (strlen(str) > LENGTH)
		{
			in.setstate(ios_base::failbit);
			return in;
		}			
		strcpy_s(temp.mass[i], str);
	}
	m = temp;

	return in;
}	

ostream & operator <<(ostream &out, const Mass_word &m)
{
	if (m.size == 0)
		out << "Массив пуст." << endl;
	else
	{ 
		out << "Слова: " << endl;
		for (int i = 0; i < m.size; i++)
			out << i + 1 << ") " << m.mass[i] << endl;
	}
	return out;
}
Mass_word & Mass_word::operator +=(const Mass_word &m) // Перегрузка опреатора +=/Добавление слова к массиву
{
	if (strlen(m.mass[0]) > LENGTH)
		throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
	if (size == SIZE)
		throw exception("Невозможно добавить слово. Массив переполнен.");
	for (int i = 0; i < size; i++)
	{ 
		if (!strcmp(m.mass[0], mass[i]))
			throw exception("Невозможно добавить слово. Оно уже есть в массиве.");
	}
	strcpy_s(mass[size], m.mass[0]);
	size = size + 1;	
	return *this;
}

const int & Mass_word::search(const Mass_word &m) // поиск слова
{
	int i = 0, check = -1;
	
	for (i = 0; i < size; i++)
		if (!strcmp(mass[i], m.mass[0])) //strcmp
		{
			check = 1;
			break;
		}
	
	if (check != 1)
		i = -1;

	return i;
 }

Mass_word Mass_word::operator() (char c) const // переделал перегрузку ()
{
	char mass_tmp[SIZE][LENGTH];
	int k = 0;

	for (int i = 0; i < size; i++)
		if (toupper(mass[i][0]) == toupper(c)) 
		{
			strcpy_s(mass_tmp[k], mass[i]);
			k++;
		}	
	Mass_word m_tmp = Mass_word(k, mass_tmp);
	
	return m_tmp;
}

Mass_word & Mass_word::sort() // метод сортировка
{	
	char tmp[LENGTH];
	char tmp_mass_1[LENGTH];
	char tmp_mass_2[LENGTH];

	for (int j = 1; j < size; j++)
		for (int i = 0; i < size - j; i++)
		{	
			strcpy_s(tmp_mass_1, mass[i + 1]);
			to_lower(tmp_mass_1);
			strcpy_s(tmp_mass_2, mass[i]);
			to_lower(tmp_mass_2);

			if (strcmp(tmp_mass_1, tmp_mass_2) < 0)
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

const char* Mass_word::operator[] (int index) const // перегрузка оператора []
{
	if (index < 0 || index >= SIZE)
		throw exception("Введено некорректное значение индекса. < 0 или > 10");
	return mass[index];
}