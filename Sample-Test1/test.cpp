#include "pch.h"
#include "gtest\\gtest.h"
#include "C:\Users\kirijuana\source\repos\OOP_LAB_1\OOP_LAB_1\Massiv_word.h"
#include <fstream>

TEST(Mass_wordConstructor, DefaultConstructor)
{
	Mass_word m;
	ASSERT_EQ(0, m.getSize());

}

TEST(Mass_wordConstructor, InitConstructors_1) // проверка конструктора с одним параметром
{
	Mass_word m("Test_word");
	
	ASSERT_EQ(1, m.getSize());

	ASSERT_STREQ("Test_word", m[0]);
	Mass_word k("1234321");
	ASSERT_STREQ("1234321", k[0]);
	Mass_word n("LetsGo");
	ASSERT_STREQ("LetsGo", n[0]);

	ASSERT_THROW(Mass_word m("Hellllllllllllllllo"), exception);
	ASSERT_THROW(Mass_word m(""), exception);
}

TEST(Mass_wordConstructor, InitConstructors_2) // проверка конструктора с двумя параметрами
{
	char mass_err[10][15] = {"Hello", "QQ", "Good", "Okey", "Lets", "Play", ""};
	ASSERT_THROW(Mass_word m(7, mass_err), exception); // проверка на пустое слово
	
	char mass[10][15] = { "Hello", "QQ", "Good", "Okey", "Lets", "Play", "why" };
	Mass_word m(7, mass);
	

	ASSERT_EQ(7, m.getSize()); // проверка на соответствие объекта массиву
	int i = 0;
	for (; i < 7; i++)
		ASSERT_STREQ(mass[i], m[i]);

	ASSERT_THROW(Mass_word m(-1, mass), exception); // проверка на выход за пределы
	ASSERT_THROW(Mass_word m(16, mass), exception);
	ASSERT_THROW(Mass_word m(0, mass), exception);
}

TEST(Mass_wordMethods, OperatorSquareBrackets) // проверка оператора []
{
	char mass[10][15] = { "Hello", "QQ", "Good", "Okey", "Hell0", "Play", "why", "Nice", "good", "new" };
	Mass_word m(10, mass);
	
	ASSERT_STREQ("Play", m[5]); 
	ASSERT_STREQ("new", m[9]);
	ASSERT_STREQ("Good", m[2]);
	ASSERT_STREQ("why", m[6]);
	
	ASSERT_THROW(m[-1], exception);
	ASSERT_THROW(m[35], exception);
	ASSERT_THROW(m[SIZE], exception);
}

TEST(Mass_wordMethods, MethodSort) // проверка метода сортировка
{
	char mass[10][15] = { "Hello", "QQ", "Good", "Okey", "Hell0", "Play", "why", "Nice", "good", "new" };
	Mass_word m(10, mass);
	char mass_sort[10][15] = { "Good", "good", "Hell0", "Hello", "new", "Nice", "Okey", "Play", "QQ", "why" };
	
	m.sort();
	for (int i = 0; i < SIZE; i++)
		ASSERT_STREQ(m[i], mass_sort[i]); // сортировка
}

TEST(Mass_wordMethods, OperatorRoundBrackets) // проверка оператора ()
{
	char mass[10][15] = { "Hello", "QQ", "Good", "Okey", "Hell0", "Play", "why", "Nice", "good", "new" };
	Mass_word m(10, mass);

	char mass_test_method[10][15] = { "Nice", "new" };
	Mass_word m_temp = m('n');
	for (int i = 0; i < 2; i++)
		ASSERT_STREQ(mass_test_method[i], m_temp[i]); 
}

TEST(Mass_wordMethods, MethodSearch) // проверка оператора ()
{
	char mass[10][15] = { "Hello", "QQ", "Good", "Okey", "Hell0", "Play", "why", "Nice", "good", "new" };
	Mass_word m(10, mass);
	
	Mass_word b = Mass_word("Hello");
	int k = m.search(b);
	ASSERT_EQ(0, k);
	b = Mass_word("QQ");
	k = m.search(b);
	ASSERT_EQ(1, k);
	b = Mass_word("Good");
	k = m.search(b);
	ASSERT_EQ(2, k);
	b = Mass_word("Okey");
	k = m.search(b);
	ASSERT_EQ(3, k);
	b = Mass_word("Hell0");
	k = m.search(b);
	ASSERT_EQ(4, k);
	b = Mass_word("Play");
	k = m.search(b);
	ASSERT_EQ(5, k);
	b = Mass_word("why");
	k = m.search(b);
	ASSERT_EQ(6, k);
	b = Mass_word("Nice");
	k = m.search(b);
	ASSERT_EQ(7, k);
	b = Mass_word("good");
	k = m.search(b);
	ASSERT_EQ(8, k);
	b = Mass_word("new");
	k = m.search(b);
	ASSERT_EQ(9, k);
}

TEST(Mass_wordMethods, OperatorPlusEquals) // проверка оператора ()
{
	char mass[10][15] = { "Nice", "new" };
	Mass_word m(2, mass);
	
	char mass_test1[10][15] = { "Nice", "new", "awp" };
	
	m += "awp";
	for (int i = 0; i < m.getSize(); i++)
		ASSERT_STREQ(mass_test1[i], m[i]); // перегрузка оператора +=

	char mass_test2[10][15] = { "Nice", "new", "awp", "test2" };
	m += "test2";
	for (int i = 0; i < m.getSize(); i++)
		ASSERT_STREQ(mass_test2[i], m[i]); // перегрузка оператора +=

	char mass_test3[10][15] = { "Nice", "new", "awp", "test2", "stream" };
	m += "stream";
	for (int i = 0; i < m.getSize(); i++)
		ASSERT_STREQ(mass_test3[i], m[i]); // перегрузка оператора +=

	ASSERT_THROW(m += "qqqqqqqqqqqqqqqqqqqqqqq", exception);
	
	char mass2[10][15] = { "Hello", "QQ", "Good", "Okey", "Hell0", "Play", "why", "Nice", "good", "new" };
	Mass_word k(10, mass2);
	ASSERT_THROW(k += "qqqqqq", exception);
	ASSERT_THROW(k += "Good", exception);
	ASSERT_THROW(k += "Hell0", exception);
	ASSERT_THROW(k += "why", exception);
	ASSERT_THROW(k += "Nice", exception);
}

TEST(Mass_wordMethods, MethodInput) // проверка оператора ()
{
	int test_size = 10;
	char mass[10][15] = { "Hello", "QQ", "Good", "Okey", "Hell0", "Play", "why", "Nice", "good", "new" };
	
	ofstream out;
	out.open("words.txt");
	if (out.is_open())
	{
		out << test_size << endl;
		for (int i = 0; i < test_size; i++)
			out << mass[i] << endl;
	}
	out.close();

	string test_str;
	ifstream filewords("words.txt");
	bool check_flag = true;

	Mass_word m = Mass_word();
	filewords >> m;

	filewords.close();

	ASSERT_EQ(test_size, m.getSize());
	for (int count = 0; count < m.getSize(); count++)
	{
		if (!strcmp(m[count], mass[count]))
			check_flag = true;
		else
			check_flag = false;
		ASSERT_EQ(true, check_flag);
	}
	
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
