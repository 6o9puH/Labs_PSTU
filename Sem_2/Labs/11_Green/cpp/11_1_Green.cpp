#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct elem
{
	int key;
	elem* next;
};


elem* unidir(int n)
{
	elem* first, * e;
	first = NULL;

	for (int i = 0; i < n; i++)
	{
		e = new(elem);
		e->key = rand();
		e->next = first;
		first = e;
	}

	return first;
}


void print_list(elem* first)
{
	if (first == NULL)
	{
		cout << "List is empty" << endl;
	}

	elem* e = first;

	while (e != NULL)
	{
		cout << e->key << endl;

		e = e->next;
	}
	
	cout << endl;
}


elem* edel(elem* first, int key)
{
	elem* e = first, * eprev = NULL;
	bool f = true;

	while (e != NULL)
	{
		if (e == first->next)
		{
			eprev = first;
		}

		if (e->key == key and f == true)
		{
			f = false;

			if (e == first)
			{
				eprev = first;
				first = e->next;
			}
			else if (e->next == NULL)
			{
				eprev->next = NULL;
				eprev = e;
			}
			else
			{
				eprev->next = e->next;
				eprev = e;
			}

			e = e->next;
			delete eprev;
			eprev = NULL;
		}
		else
		{
			e = e->next;

			if (eprev != NULL)
			{
				eprev = eprev->next;
			}
		}
	}

	print_list(first);

	return first;
}


elem* eadd(elem* first, int key)
{
	elem* e = first, * eprev = NULL;
	bool f = true;

	while (e != NULL)
	{
		if (e == first->next)
		{
			eprev = first;
		}

		if (e->key == key and f == true)
		{
			f = false;
			elem* el = new(elem);

			cout << "Enter element" << endl;
			cin >> key;
			cout << endl;

			el->key = key;
			el->next = e;

			if (e == first)
			{
				first = el;
			}
			else
			{
				eprev->next = el;
			}
		}

		e = e->next;

		if (eprev != NULL)
		{
			eprev = eprev->next;
		}
	}

	print_list(first);

	return first;
}


void inserter(elem* first)
{
	elem* e = first;
	FILE* f = fopen("L11_1F.bin", "wb");

	while (e != NULL)
	{
		fwrite(e, sizeof(elem), 1, f);
		e = e->next;
	}

	fclose(f);

	cout << "List saved" << endl;
}


void deleter(elem* first)
{
	elem* e = first, *eprev;
	
	while (e != NULL)
	{
		eprev = e;
		e = e->next;
		delete eprev;
	}

	cout << "List deleted" << endl;

	print_list(e);
}


elem* restorer()
{
	elem* first = NULL, e, * el, * eprev;
	FILE* f = fopen("L11_1F.bin", "rb");

	fread(&e, sizeof(elem), 1, f);
	el = new(elem);
	el->key = e.key;
	eprev = el;
	first = el;

	while (fread(&e, sizeof(elem), 1, f) == 1)
	{
		el = new(elem);
		el->key = e.key;
		eprev->next = el;
		eprev = el;
	}
	
	el->next = NULL;
	fclose(f);

	cout << "List loaded" << endl;

	print_list(first);

	return first;
}


int main()
{
	int n, key;
	elem* first;

	cout << "Enter number of elements" << endl;
	cin >> n;
	cout << endl;

	first = unidir(n);
	print_list(first);

	cout << "Enter element to delete" << endl;
	cin >> key;
	cout << endl;

	first = edel(first, key);

	cout << "Enter element to add another" << endl;
	cin >> key;
	cout << endl;

	first = eadd(first, key);
	inserter(first);
	deleter(first);
	first = restorer();
	deleter(first);

	return 0;
}