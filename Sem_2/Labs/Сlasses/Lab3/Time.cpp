#include "Time.h"
#include <iostream>

using namespace std;

Time& Time::operator=(const Time&t)
{
	if (&t == this)
	{
		return *this;
	}

	min = t.min;
	sec = t.sec;

	return *this;
}

Time Time::operator-(const Time&t)
{
	int temp = min * 60 + sec - t.min * 60 - t.sec;
	Time p;
	p.min = temp / 60;
	p.sec = temp % 60;

	return p;
}

bool Time::operator!=(const Time& t)
{
	if ((min * 60 + sec) != (t.min * 60 + t.sec))
	{
		return true;
	}
	else
	{
		return false;
	}
}

istream& operator>>(istream& in, Time& t)
{
	cout << "Minutes:\n";
	in >> t.min;
	cout << "Seconds:\n";
	in >> t.sec;

	return in;
}

ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << " : " << t.sec);
}