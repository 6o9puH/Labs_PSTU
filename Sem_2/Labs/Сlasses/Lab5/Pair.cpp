#include "Pair.h"

Pair::Pair()
{
	first = 0;
	second = 0;
}

Pair::~Pair()
{
}

Pair::Pair(int F, int S)
{
	first = F;
	second = S;
}

Pair::Pair(const Pair& pair)
{
	first = pair.first;
	second = pair.second;
}

void Pair::Set_first(int F)
{
	first = F;
}

void Pair::Set_second(int S)
{
	second = S;
}

int Pair::Prod(int F, int S)
{
	return F * S;
}

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)
	{
		return *this;
	}

	first = p.first;
	second = p.second;

	return *this;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "First: ";
	in >> p.first;
	cout << "Second: ";
	in >> p.second;
	cout << endl;

	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << "First: " << p.first << "\nSecond: " << p.second << endl;

	return out;
}

void Pair::Show()
{
	cout << "First: " << first << "\nSecond: " << second << endl;
}