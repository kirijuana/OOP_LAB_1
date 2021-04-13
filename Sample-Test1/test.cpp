#include "pch.h"
#include "gtest\\gtest.h"
#include "C:\Users\kirijuana\source\repos\OOP_LAB_1\OOP_LAB_1\Massiv_word.h"

TEST(Mass_wordConstructor, DefaultConstructor)
{
	Mass_word m;
	ASSERT_EQ(0, m.getSize());

}

TEST(Mass_wordConstructor, InitConstructors_1)
{
	Mass_word m("Test_word");
	
	ASSERT_EQ(1, m.getSize());
	ASSERT_STREQ("Test_word", m[0]);
}

TEST(Mass_wordConstructor, InitConstructors_2)
{
	char mass[10][15] = {"Hello", "QQ", "Good", "Okey", "Lets", "Play", "why"};
	Mass_word m(7, mass);

	ASSERT_EQ(7, m.getSize());
	int i = 0;
	for (; i < 7; i++)
		ASSERT_STREQ(mass[i], m[i]);
}

TEST(Mass_wordConstructor, TestException)
{
	char mass[10][15] = { "Hello", "QQ", "Good", "Okey", "Hell0", "Play", "why" };
	ASSERT_ANY_THROW(Mass_word m("Hellllllllllllllllo"));
	ASSERT_ANY_THROW(Mass_word m(-1, mass));
}

TEST(Mass_wordMethods, Parameters)
{

	char mass[10][15] = { "Hello", "QQ", "Good", "Okey", "Hell0", "Play", "why", "Nice", "good", "new"};
	
	Mass_word m(7, mass);
	ASSERT_STREQ("Play", m[5]); //перегруженный оператор []

	char mass_sort[10][15] = { "Good", "good", "Hello", "Hell0", "new", "Nice", "Okey", "Play", "QQ", "why" };
	m.sort();
	for(int i = 0; i < SIZE; i++)
		ASSERT_STREQ(mass_sort[i], m[i]); // сортировка

	char mass_test_method[10][15] = { "new", "Nice" };
	m('c');
	for (int i = 0; i < SIZE; i++)
		ASSERT_STREQ(mass_test_method[i], m[i]); // перегрузка оператора ()
	
	ASSERT_EQ(1, m.search("Nice"));

	char mass_test_method_2[10][15] = { "new", "Nice", "awp" };
	ASSERT_ANY_THROW(m += "awp");
	for (int i = 0; i < SIZE; i++)
		ASSERT_STREQ(mass_test_method_2[i], m[i]); // перегрузка оператора +=

}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
