#include <iostream>

using namespace std;

int main()
{
	const int c = 10;
	int p, q;

	cin >> p >> q;

	int a[c];

	cout << endl;

	for (int i = 0; i < c; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << endl;
	}

	cout << endl;

	while (p < q)
	{
		int t = a[p];
		a[p] = a[q];
		a[q] = t;
		p++;
		q--;
	}

	for (int i = 0; i < c; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}