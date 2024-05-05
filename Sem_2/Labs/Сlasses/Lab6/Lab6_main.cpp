#include "Vector.h"
#include <iostream>

using namespace std;

void main()
{
	Vector a(5);

	cout << "Vector A:\n" << a << endl << "Enter A:\n";
	cin >> a;
	cout << "Vector A:\n" << a << endl;

	a[2] = 100;

	cout << "Vector A:\n" << a << endl;

	Vector b(10);

	cout << "Vector B:\n" << b << endl;

	Vector c(10);
	c = b + a;

	cout << "Vector C:\n" << c << endl;
	cout << "Length of A: " << a() << endl;

	for (Iterator i = a.first(); i != a.last(); i + 1)
	{
		cout << *i << endl;
	}
}