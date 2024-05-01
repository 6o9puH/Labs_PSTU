#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
	Time a, b, c;

	cout << "Enter a:" << endl;
	cin >> a;
	cout << "Enter b:" << endl;
	cin >> b;

	c = a - b;

	cout << "a != b is ";

	if (a != b)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = a - b = " << c << endl;
}