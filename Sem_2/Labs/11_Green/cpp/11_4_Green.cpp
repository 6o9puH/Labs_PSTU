#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct elem
{
	int key;
	elem* next;
};


struct queue
{
	elem* front, * back;
	int size;

	void init()
	{
		front = nullptr;
		back = nullptr;
		size = 0;
	}

	void push(int key)
	{
		elem* cur = new elem;
		cur->key = key;
		cur->next = nullptr;

		if (size == 0)
		{
			front = cur;
			back = cur;
		}
		else
		{
			back->next = cur;
			back = cur;
		}

		size++;
	}

	int pop()
	{
		int key = front->key;
		elem* tmp = front;
		
		if (size == 1)
		{
			back = nullptr;
		}

		front = front->next;
		size--;
		delete tmp;
		return key;
	}
};


queue new_queue (int size)
{
	queue q;
	q.init();

	for (int i = 0; i < size; i++)
	{
		q.push(rand());
	}

	return q;
}


void print_queue(queue q)
{
	if (q.front == nullptr)
	{
		cout << "Queue is empty" << endl;
	}

	elem* e = q.front;
	
	while (e != nullptr)
	{
		cout << e->key << endl;

		e = e->next;
	}

	cout << endl;
}


queue edel(queue q, int key)
{
	queue tmp;
	tmp.init();

	while (q.size != 0)
	{
		if (q.front->key != key)
		{
			tmp.push(q.pop());
		}
		else
		{
			q.pop();
		}
	}

	while (tmp.size != 0)
	{
		q.push(tmp.pop());
	}

	print_queue(q);
		
	return q;
}


queue eadd(queue q, int key)
{
	queue tmp;
	tmp.init();

	while (q.size != 0)
	{
		if (q.front->key == key)
		{
			int nkey;

			cout << "Enter element" << endl;
			cin >> nkey;
			cout << endl;

			tmp.push(nkey);
		}
		tmp.push(q.pop());
	}

	while (tmp.size != 0)
	{
		q.push(tmp.pop());
	}

	print_queue(q);

	return q;
}


void inserter(queue q)
{
	elem* e = q.front;
	FILE* f = fopen("L11_4F.bin", "wb");

	while (e != nullptr)
	{
		fwrite(&e->key, sizeof(int), 1, f);
		e = e->next;
	}

	fclose(f);
	
	cout << "Queue saved" << endl;
}


void deleter(queue q)
{
	while (q.size != 0)
	{
		q.pop();
	}

	cout << "Queue deleted" << endl;

	print_queue(q);
}


queue restorer()
{
	int e;
	queue q;
	q.init();
	FILE* f = fopen("L11_4F.bin", "rb");

	while (fread(&e, sizeof(int), 1, f) == 1)
	{
		q.push(e);
	}

	fclose(f);

	cout << "Queue loaded" << endl;

	print_queue (q);

	return q;
}


int main()
{
	int size, key;
	queue q;

	cout << "Enter number of elements" << endl;
	cin >> size;
	cout << endl;

	q = new_queue(size);
	print_queue(q);

	cout << "Enter element to delete" << endl;
	cin >> key;
	cout << endl;

	q = edel(q, key);

	cout << "Enter element to add another" << endl;
	cin >> key;
	cout << endl;

	q = eadd(q, key);
	inserter(q);
	deleter(q);
	q = restorer();
	deleter(q);

	return 0;
}