#include "money.h"
#include <iostream>

using namespace std;

void fraction::Init(int F, int S)
{
	if ((F != 1) and (F != 2) and (F != 5) and (F != 10) and (F != 50) and (F != 500) and (F != 1000) and (F != 5000)
		or S < 0)
	{
		cout << "Invalid values";
		exit(0);
	}

	first = F;
	second = S;
}

void fraction::Read()
{
	cout << "Enter first\n";
	cin >> first;
	cout << "Enter second\n";
	cin >> second;

	if ((first != 1) and (first != 2) and (first != 5) and (first != 10) and (first != 50) and (first != 500) and (first != 1000) and (first != 5000)
		or second < 0)
	{
		cout << "Invalid values";
		exit(0);
	}
}

void fraction::Show()
{
	cout << "First: " << first;
	cout << "\nSecond: " << second << endl;;
}

int fraction::summa()
{
	return first * second;
}