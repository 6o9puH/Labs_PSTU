#include "Pair.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

void main()
{
	Pair a;

	cout << "Enter A:\n";
	cin >> a;
	cout << "A:\n" << a;

	Pair b(4, 115);

	cout << "B:\n" << b;

	a = b;

	cout << "A:\n" << a;

	Rectangle c;
	
	cout << "Enter C:\n";
	cin >> c;
	cout << "C: \n" << c << "Area C:" << c.area() << "\nPerimeter C: " << c.perimeter();
}