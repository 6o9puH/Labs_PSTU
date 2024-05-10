#include "Vector.h"
#include "Error.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		Vector x(5);
		Vector y;
		cout << "X(5):\n" << x;
		int i;
		cout << "X(i), enter i:\n";
		cin >> i;
		cout << "X(" << i << "):\n" << x[i] << endl;
		cout << "y = x + 3; enter X(5), X(6), X(7):\n";
		y = x + 3;
		cout << "Y:\n" << y;
		x - 2;
		cout << "X - 2\nX:\n" << x;
		x + 2;
		cout << "X + 2; enter X(6), X(7):\n" << x;
		cout << "Size of x: " << x() << endl;
	}
	catch (error e) { e.what(); }

	return 0;
}