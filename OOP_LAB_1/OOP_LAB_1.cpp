#include "pch.h"
#include <iostream>

#include "Massiv_word.h"

int main()
{
	setlocale(LC_ALL, "");
	Mass_word m;
	int menu = -1;
	do
	{
		cout << "Введите:" << endl;
		cout << "1. Для создания экземпляра класса с инициализацией одним словом, т.е. строкой символов" << endl;
		cout << "2. Для создания экземпляров класса с инициализацией количеством слов и словами из массива строковых констант" << endl;
		cout << "3. Для ввода экземпляров класса из входного потока" << endl;
		cout << "4. Для вывода экземпляров класса в выходной поток" << endl;
		cout << "5. Для добавления слова к массиву слов" << endl;
		cout << "6. Для поиска слова в массиве" << endl;
		cout << "7. Для выделения слова по его номеру в массиве" << endl;
		cout << "8. Для формирования массива слов, начинающихся на заданный символ без учета регистра" << endl;
		cout << "9. Для упорядочивания слов в массиве по алфавиту" << endl;
		cout << "10. Для создания пустого экземпляра класса" << endl;
		cout << "0. Для выхода." << endl;
		
		cin >> menu;
		system("cls");

		if (menu == 1)
		{
			cout << "Введите строку:" << endl;
			char str[LENGTH];
			cin >> str;
			m = Mass_word(str);
		}
		else if (menu == 2)
		{
			cout << "Введите количество слов:" << endl;
			int size;
			cin >> size;
			cout << "Введите " << size << " слов: " << endl;
			char mass[SIZE][LENGTH];
			for (int i = 0; i < size; i++)
			{
				cin >> mass[i];
				for (int j = 0; j < i; j++)
				{
					if (!strcmp(mass[i], mass[j]))
					{
						cout << "Слово " << mass[i] << " уже есть в массиве. Введите другое слово." << endl;
						i--;
						break;
					}
				}
			}
			m = Mass_word(size, mass);
		}
		else if (menu == 3)
		{
			m = Mass_word();
			cout << "Введите " << SIZE << " слов:" << endl;
			cin >> m;
		}
		else if (menu == 4)
		{
			cout << m;
		}
		else if (menu == 5)
		{
			char str[LENGTH];
			int check = 0;
			do 
			{
				cout << "Введите слово:" << endl;
				cin >> str;
				for (int i = 0; i < SIZE; i++)
				{
					if (!strcmp(str, m[i]))
					{
						cout << "Слово " << str << " уже есть в массиве. Попробуйте добавить другое слово." << endl;
						check = 1;
						break;
					}
					check = 0;
				}
			} while (check);
			m += str;
		}
		else if (menu == 6)
		{
			char str[LENGTH];
			cout << "Введите слово:" << endl;
			cin >> str;
			m.search(str);
		}
		else if (menu == 7)
		{
			int index = 0;
			cin >> index;
			cout << "Введите индекс слова для его вывода на экран." << endl;
			cout << m[index];
		}
		else if (menu == 8)
		{
			cout << "Введите символ." << endl;
			char symb;
			cin >> symb;
			m(symb);
		}
		else if (menu == 9)
		{
			m.sort();
			cout << "Массив упорядочен." << endl;
		}

	} while (menu != 0);

	system("pause");
}

