#pragma once
#include "Object.h"
#include "Event.h"

class Vector
{
public:
	Vector();
	Vector(int);
	~Vector();
	void Add();
	void Add(Object*);
	void Del();
	void Show();
	void Show(int);
	int operator()();
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};