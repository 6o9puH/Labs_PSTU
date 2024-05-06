#pragma once
#include <iostream>

using namespace std;

class Time
{
public:
	Time();
	Time(int, int);
	Time(const Time&);
	Time& operator=(const Time&);
	friend ostream& operator<<(ostream& out, const Time&);
	friend istream& operator>>(istream& in, Time&);
	Time operator+(Time);

	virtual ~Time()
	{
	}
private:
	int min, sec;
};

