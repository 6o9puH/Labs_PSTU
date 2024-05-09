#include "Vector.h"
#include "Employee.h"
#include <iostream>

using namespace std;

Vector::Vector()
{
	beg = nullptr;
	size = 0;
	cur = 0;
}

Vector::~Vector()
{
	if (beg != 0) delete[] beg;
	beg = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Add()
{
	Object* p;
	int y;
	
	cout << "1.Person\n2.Employee\n";
	cin >> y;

	if (y == 1)
	{
		Person* a = new Person;
		a->Input();
		p = a;
		
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
	{
		if (y == 2)
		{
			Employee* b = new Employee;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
	}
}

void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
}

void Vector::Show()
{
	if (cur == 0) cout << "Empty\n";
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

void Vector::Show(int a)
{
	if (a < 0 or a >= cur or cur == 0) cout << "Wrong number!\n";
	else
	{
		Object** p = beg;
		for (int i = 0; i < a; i++)
		{
			p++;
		}
		(*p)->Show();
	}
}

int Vector::operator()()
{
	return cur;
}

void Vector::Del()
{
	if (cur == 0) return;
	cur--;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;

		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}