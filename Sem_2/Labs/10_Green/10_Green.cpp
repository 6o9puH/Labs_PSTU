#include <iostream>

using namespace std;

int main()
{
	int n, ndel, nadd , eadd;

	cout << "Enter number of elements" << endl;
	cin >> n;

	int *a = new int[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}

	cout << endl;

	cout << "Enter number to delete [1;n]" << endl;
	cin >> ndel;

	int* b = new int[n - 1];
	int j = 0;

	for (int i = 0; i < n; i++)
	{
		if (i != ndel - 1)
		{
			b[j] = a[i];
			j++;
		}
	}

	cout << endl;

	for (int i = 0; i < n - 1; i++)
	{
		cout << b[i] << endl;
	}

	cout << "Enter number to add an element [1;n]" << endl;
	cin >> nadd;
	cout << "Enter element" << endl;
	cin >> eadd;

	int* c = new int[n];

	for (int i = 0; i < nadd; i++)
	{
		c[i] = b[i];
	}

	c[nadd] = eadd;

	for (int i = nadd + 1; i < n; i++)
	{
		c[i] = b[i - 1];
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << c[i] << endl;
	}

	delete[] a;
	delete[] b;
	delete[] c;

	return 0;
}