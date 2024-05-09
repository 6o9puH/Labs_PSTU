#include "Person.h"
#include <iostream>
#include "Event.h"

Person::Person()
{
	name = "";
	age = 0;
}

Person::~Person()
{
}

Person::Person(string N, int A)
{
	name = N;
	age = A;
}

Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}

void Person::Set_name(string N)
{
	name = N;
}

void Person::Set_age(int A)
{
	age = A;
}

Person& Person::operator=(const Person& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

void Person::Show()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

void Person::Input()
{
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet: 
			cout << "Name = " << Get_name() << endl;
			break;
		}
	}
}