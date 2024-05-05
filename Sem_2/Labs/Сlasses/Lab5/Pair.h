#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Pair :
	public Object
{
public:
	Pair();
	virtual ~Pair();
	void Show();
	Pair(int, int);
	Pair(const Pair&);

	int Get_first()
	{
		return first;
	}

	int Get_second()
	{
		return second;
	}

	void Set_first(int);
	void Set_second(int);
	int Prod(int, int);
	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);

protected:
	int first;
	int second;
};

