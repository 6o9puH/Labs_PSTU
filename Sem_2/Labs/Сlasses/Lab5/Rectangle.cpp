#include "Rectangle.h"

Rectangle::Rectangle() :Pair()
{
}

Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(int F, int S) :Pair(F, S)
{
}

Rectangle::Rectangle(const Rectangle& r)
{
	first = r.first;
	second = r.second;
}

int Rectangle::area()
{
	return first * second;
}

int Rectangle::perimeter()
{
	return (first + second) * 2;
}

Rectangle& Rectangle::operator=(const Rectangle& r)
{
	if (&r == this)
	{
		return *this;
	}

	first = r.first;
	second = r.second;
	return *this;
}

istream& operator>>(istream& in, Rectangle& r)
{
	cout << "First: ";
	in >> r.first;
	cout << "Second: ";
	in >> r.second;
	cout << endl;

	return in;
}

ostream& operator<<(ostream& out, const Rectangle& r)
{
	out << "First: " << r.first;
	out << "\nSecond: " << r.second << endl;

	return out;
}

void Rectangle::Show()
{
	cout << "First: " << first;
	cout << "\nSecond: " << second;
	cout << "\nArea: " << area();
	cout << "\nPerimeter: " << perimeter() << endl;
}