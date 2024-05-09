#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee() :Person()
{
	salary = 0;
	job = "";
}

Employee::~Employee() {}

Employee::Employee(string N, int A, float S, string J):Person(N, A)
{
	salary = S;
	job = J;
}

Employee::Employee(const Employee& E)
{
	name = E.name;
	age = E.age;
	salary = E.salary;
	job = E.job;
}

void Employee::Set_salary(float S)
{
	salary = S;
}

void Employee::Set_job(string J)
{
	job = J;
}

Employee& Employee::operator=(const Employee& E)
{
	if (&E == this) return *this;
	name = E.name;
	age = E.age;
	salary = E.salary;
	job = E.job;

	return *this;
}

void Employee::Show()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Salary: " << salary << endl;
	cout << "Job: " << job << endl;
}

void Employee::Input()
{
	cout << "Name: "; cin >> name;
	cout << "Age: "; cin >> age;
	cout << "Salary: "; cin >> salary;
	cout << "Job: "; cin >> job;
}