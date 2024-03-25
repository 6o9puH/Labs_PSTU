#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct elem
{
	int key;
	elem* next, * prev;
};


elem* bidir(int n)
{
	elem* start = NULL, * e, * p;
	p = new elem;
	p->key = rand();
	p->next = NULL;
	p->prev = NULL;
	start = p;

	for (int i = 0; i < n - 1; i++)
	{
		e = new(elem);
		e->key = rand();
		e->next = NULL;
		e->prev = p;
		p->next = e;
		p = e;
		start = e;
	}

	return start;
}


void print_list(elem* e)
{
	if (e == NULL)
	{
		cout << "List is empty" << endl;
	}

	while (e != NULL)
	{
		cout << e->key << endl;

		e = e->prev;
	}

	cout << endl;
}


elem* edel(elem* start, int key)
{
	elem* e = start, * n = NULL;
	bool f = true;

	while (e != NULL)
	{
		if (e == start->prev)
		{
			n = start;
		}

		if (e->key == key and f == true)
		{
			f = false;

			if (e == start)
			{
				start = e->prev;
				start->next = NULL;
			}
			else if (e->prev == NULL)
			{
				n->prev = NULL;
			}
			else
			{
				n->prev = e->prev;
				n = n->prev;
				n->next = e->next;
			}

			n = e;
			e = e->prev;
			delete n;
			n = NULL;
		}
		else
		{
			e = e->prev;

			if (n != NULL)
			{
				n = n->prev;
			}
		}
	}

	print_list(start);

	return start;
}


elem* eadd(elem* start, int key)
{
	elem* e = start, * n = NULL;
	bool f = true;

	while (e != NULL)
	{
		if (e == start->prev)
		{
			n = start;
		}

		if (e->key == key and f == true)
		{
			f = false;
			elem* el = new(elem);

			cout << "Enter element" << endl;
			cin >> key;
			cout << endl;

			el->key = key;
			el->prev = e;
			e->next = el;

			if (e == start)
			{
				start = el;
				el->next = NULL;
			}
			else
			{
				n->prev = el;
				el->next = n;
			}

			e = e->next;
		}

		e = e->prev;

		if (n != NULL)
		{
			n = n->prev;
		}
	}

	print_list(start);

	return start;
}


void inserter(elem* e)
{
	FILE* f = fopen("L11_2F.bin", "wb");

	while (e != NULL)
	{
		fwrite(e, sizeof(elem), 1, f);
		e = e->prev;
	}

	fclose(f);

	cout << "List saved" << endl;
}


void deleter(elem* e)
{
	elem* n;

	while (e != NULL)
	{
		n = e;
		e = e->prev;
		delete n;
	}

	cout << "List deleted" << endl;

	print_list(e);
}


elem* restorer()
{
	elem* start = NULL, e, * el, * n;
	FILE* f = fopen("L11_2F.bin", "rb");

	fread(&e, sizeof(elem), 1, f);
	el = new(elem);
	el->key = e.key;
	el->next = NULL;
	el->prev = NULL;
	n = el;
	start = el;

	while (fread(&e, sizeof(elem), 1, f) == 1)
	{
		el = new(elem);
		el->key = e.key;
		el->prev = NULL;
		el->next = n;
		n->prev = el;
		n = el;
	}

	fclose(f);

	cout << "List loaded" << endl;

	print_list(start);

	return start;
}


int main()
{
	int n, key;
	elem* start;

	cout << "Enter number of elements" << endl;
	cin >> n;
	cout << endl;

	start = bidir(n);
	print_list(start);

	cout << "Enter element to delete" << endl;
	cin >> key;
	cout << endl;

	start = edel(start, key);

	cout << "Enter element to add another" << endl;
	cin >> key;
	cout << endl;

	start = eadd(start, key);
	inserter(start);
	deleter(start);
	start = restorer();
	deleter(start);

	return 0;
}