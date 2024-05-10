#pragma once
#include <iostream>

using namespace std;

const int MAX_SIZE = 30;
class Vector
{
	int size;
	int* beg;
public:
	Vector() { size = 0; beg = 0; }
	Vector(int s);
	Vector(int s, int* mas);
	Vector(const Vector&);
	~Vector();
	const Vector& operator=(const Vector&);
	int operator[](int);
	int operator()();
	Vector operator-(int);
	Vector operator+(int);
	friend ostream& operator<<(ostream& out, const Vector&);
	friend istream& operator>>(istream& in, Vector&);
};