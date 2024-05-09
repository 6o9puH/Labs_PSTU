#pragma once
#include "Person.h"

class Employee:
	public Person
{
public:
	Employee();
	~Employee();
	void Show();
	void Input();
	Employee(string, int, float, string);
	Employee(const Employee&);
	float Get_salary() { return salary; }
	string Get_job() { return job; }
	void Set_salary(float);
	void Set_job(string);
	Employee& operator=(const Employee&);
protected:
	float salary;
	string job;
};

