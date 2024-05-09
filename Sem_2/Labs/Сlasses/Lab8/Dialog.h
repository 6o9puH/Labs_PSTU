#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog :
	public Vector
{
public:
	Dialog();
	virtual ~Dialog();
	virtual void GetEvent(TEvent&);
	virtual int Execute();
	virtual void HandleEvent(TEvent&);
	virtual void ClearEvent(TEvent&);
	int Valid();
	void EndExec();
protected:
	int EndState;
};

