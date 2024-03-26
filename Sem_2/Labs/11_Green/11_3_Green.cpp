#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct elem
{
	int key;
	elem* next;
};


struct stack
{
	elem* top;
	int size;

	void init()
	{
		top = nullptr;
		size = 0;
	}

	void push(int key)
	{
		elem* cur = new elem;
		cur->key = key;
		cur->next = top;
		top = cur;
		size++;
	}

	int pop()
	{
		int key = top->key;
		elem* tmp = top;
		top = top->next;
		size--;
		delete tmp;
		return key;
	}
};


stack new_stack (int size)
{
	stack s;
	s.init();

	for (int i = 0; i < size; i++)
	{
		s.push(rand());
	}

	return s;
}


void print_stack(stack s)
{
	if (s.top == nullptr)
	{
		cout << "Stack is empty" << endl;
	}

	elem* e = s.top;

	while (e != nullptr)
	{
		cout << e->key << endl;

		e = e->next;
	}

	cout << endl;
}


stack edel(stack s, int key)
{
	stack tmp;
	tmp.init();

	while (s.size != 0)
	{
		if (s.top->key != key)
		{
			tmp.push(s.pop());
		}
		else
		{
			s.pop();
		}
	}

	while (tmp.size != 0)
	{
		s.push(tmp.pop());
	}

	print_stack(s);
		
	return s;
}


stack eadd(stack s, int key)
{
	stack tmp;
	tmp.init();

	while (s.size != 0)
	{
		if (s.top->key == key)
		{
			int nkey;
			cout << "Enter element" << endl;
			cin >> nkey;
			cout << endl;

			tmp.push(nkey);
		}
		tmp.push(s.pop());
	}

	while (tmp.size != 0)
	{
		s.push(tmp.pop());
	}

	print_stack(s);

	return s;
}


stack inserter(stack s)
{
	stack tmp;
	tmp.init();

	while (s.size != 0)
	{
		tmp.push(s.pop());
	}

	elem* e = tmp.top;
	FILE* f = fopen("L11_3F.bin", "wb");

	while (e != nullptr)
	{
		fwrite(&e->key, sizeof(int), 1, f);
		e = e->next;
	}

	fclose(f);

	while (tmp.size != 0)
	{
		s.push(tmp.pop());
	}
	
	cout << "Stack saved" << endl;

	return s;
}


void deleter(stack s)
{
	while (s.size != 0)
	{
		s.pop();
	}

	cout << "Stack deleted" << endl;

	print_stack(s);
}


stack restorer()
{
	int e;
	stack s;
	s.init();
	FILE* f = fopen("L11_3F.bin", "rb");

	while (fread(&e, sizeof(int), 1, f) == 1)
	{
		s.push(e);
	}

	fclose(f);

	cout << "Stack loaded" << endl;

	print_stack(s);

	return s;
}


int main()
{
	int n, key;
	stack s;

	cout << "Enter number of elements" << endl;
	cin >> n;
	cout << endl;

	s = new_stack(n);
	print_stack(s);

	cout << "Enter element to delete" << endl;
	cin >> key;
	cout << endl;

	s = edel(s, key);

	cout << "Enter element to add another" << endl;
	cin >> key;
	cout << endl;

	s = eadd(s, key);
	s = inserter(s);
	deleter(s);
	s = restorer();
	deleter(s);

	return 0;
}