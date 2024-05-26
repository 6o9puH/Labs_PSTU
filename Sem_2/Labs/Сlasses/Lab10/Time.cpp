#include "Time.h"

Time::Time()
{
	min = 0;
	sec = 0;
}

Time::~Time(){}

Time::Time(int M, int S)
{
	min = M;
	sec = S;
}

Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}

Time Time::operator=(const Time&t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

Time Time::operator-(const Time& t)
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

bool Time::operator<(const Time& t)
{
	if ((min * 60 + sec) < (t.min * 60 + t.sec))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream&out, const Time& t)
{
	out << t.min << " : " << t.sec << endl;
	return out;
}

istream& operator>>(istream& in, Time& t)
{
	cout << "Min: "; in >> t.min;
	cout << "Sec: "; in >> t.sec;
	return in;
}

fstream& operator>>(fstream& fin, Time& t)
{
	fin >> t.min;
	fin >> t.sec;
	return fin;
}

fstream& operator<<(fstream& fout, const Time& t)
{
	fout << t.min << "\n" << t.sec << "\n";
	return fout;
}