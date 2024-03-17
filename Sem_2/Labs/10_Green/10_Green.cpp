#include <iostream>

using namespace std;

int main()
{
	int n, edel, eadd;

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

	cout << "Enter element to delete" << endl;
	cin >> edel;

	int* b = new int[n - 1];
	int j = 0;
	bool f = true;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == edel and f == true)
		{
			f == false;
			continue;
		}
		b[j] = a[i];
		j++;
	}

	cout << endl;

	for (int i = 0; i < n - 1; i++)
	{
		cout << b[i] << endl;
	}

	cout << endl;

	cout << "Enter element to add" << endl;
	cin >> eadd;

	int* c = new int[n];

	for (int i = 0; i < n - 1; i++)
	{
		c[i] = b[i];
	}

	c[n - 1] = eadd;

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