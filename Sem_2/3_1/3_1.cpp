#include <iostream>

using namespace std;

int main()
{
	const int c = 10;
	int a [c];

	for (int i = 0; i < c; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < c / 2; i++)
	{
		int t = a[c - 1 - i];
		a[c - 1 - i] = a[i];
		a[i] = t;
	}

	for (int i = 0; i < c; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}