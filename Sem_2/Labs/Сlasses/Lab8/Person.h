#pragma once
#include "Object.h"
#include <string>

using namespace std;

class Person :
	public Object
{
public:
	Person();
	virtual ~Person();
	void Show();
	void Input();
	Person(string, int);
	Person(const Person&);
	string Get_name(){ return name; }
	int Get_age() { return age; }
	void Set_name(string);
	void Set_age(int);
	Person& operator=(const Person&);
	void HandleEvent(const TEvent& e);
protected:
	string name;
	int age;
};

