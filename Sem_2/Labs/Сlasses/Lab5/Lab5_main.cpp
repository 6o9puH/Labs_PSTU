#include "Object.h"
#include "Pair.h"
#include "Rectangle.h"
#include "Vector.h"
#include <iostream>

using namespace std;

void main()
{
	Vector v(5);
	Pair a;

	cout << "Enter A:\n";
	cin >> a;

	Rectangle b;
	
	cout << "Enter rectangle B:\n";
	cin >> b;

	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);

	cout << v;
}