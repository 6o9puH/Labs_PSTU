#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Time
{
	int min;
	int sec;
public:
	Time();
	~Time();
	Time(int, int);
	Time(const Time&);
	Time operator=(const Time&);
	Time operator-(const Time&);
	bool operator!=(const Time&);
	bool operator<(const Time&);
	friend ostream& operator<<(ostream& out, const Time&);
	friend istream& operator>>(istream& inr, Time&);
	friend fstream& operator>>(fstream& fin, Time&);
	friend fstream& operator<<(fstream& fout, const Time&);
};

