#pragma once
#include <iostream>

using namespace std;

class Iterator
{
	friend class Vector;
public:
	Iterator()
	{
		elem = 0;
	}

	Iterator(const Iterator& it)
	{
		elem = it.elem;
	}

	bool operator==(const Iterator& it)
	{
		return (elem == it.elem);
	}

	bool operator!=(const Iterator& it)
	{
		return (elem != it.elem);
	}

	void operator+(int n)
	{
		elem += n;
	}

	int& operator *() const 
	{ 
		return*elem; 
	}
private:
	int* elem;
};

class Vector
{
public:
	Vector(int, int k = 0);
	Vector(const Vector&);
	~Vector();
	Vector& operator=(const Vector&);
	int& operator[](int);
	Vector operator+(const Vector&);
	int operator()();
	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream&, Vector&);
	Iterator first()
	{
		return beg;
	}
	Iterator last()
	{
		return end;
	}
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};