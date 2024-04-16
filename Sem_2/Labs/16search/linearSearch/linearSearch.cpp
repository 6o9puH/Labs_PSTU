#include <iostream>

using namespace std;

struct arr
{
	int* a;
	int size;
};

int* createArray(int size, int max, int min)
{
	srand(time(0));
	int* a = new int[size];

	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % max + min;

		cout << a[i] << " ";
	}

	cout << endl << endl;

	return a;
}


void linearSearch(arr a)
{
	int key;
	bool f = false;

	cout << "Enter key" << endl;
	cin >> key;

	for (int i = 0; i < a.size; i++)
	{
		if (a.a[i] == key)
		{
			f = true;
			cout << i + 1 << " ";
		}
	}

	if (f == false)
	{
		cout << "Element not found";
	}

	cout << endl << "!!!!! !!!!! !!!!! !!!!! !!!!!" << endl;

	linearSearch(a);
}


int main()
{
	int n = 0, max = -1, min = -1, key;
	arr a;

	while (n <= 0)
	{
		cout << "Enter number of elements" << endl;
		cin >> n;
	}

	while (max < 0)
	{
		cout << "Enter maximum value (>= 0)" << endl;
		cin >> max;
	}

	while (min < 0)
	{
		cout << "Enter minimum value (>= 0)" << endl;
		cin >> min;
	}

	a.a = createArray(n, max, min);
	a.size = n;

	linearSearch(a);

	return 0;
}