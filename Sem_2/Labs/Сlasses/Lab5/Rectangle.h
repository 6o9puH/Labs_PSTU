#pragma once
#include "Pair.h"
class Rectangle : 
	public Pair
{
public:
	Rectangle();
	~Rectangle();
	void Show();
	Rectangle(int, int);
	Rectangle(const Rectangle&);
	int area();
	int perimeter();
	Rectangle& operator=(const Rectangle&);
	friend istream& operator>>(istream& in, Rectangle& r);
	friend ostream& operator<<(ostream& out, const Rectangle& r);
};