#include <iostream>

using namespace std;

int main()
{
	const int c = 10;
	int t, k, a[c];

	cin >> k;
	cout << endl;

	for (int i = 0; i < c; i++)
	{
		a[i] = rand() % 100;

		cout << a[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < c - 1; j++)
		{
			if (j == 0)
			{
				t = a[c - 1];
				a[c - 1] = a[j];
				a[j] = a[j + 1];
			}
			else if (j == c - 2)
			{
				a[j] = t;
			}
			else
			{
				a[j] = a[j + 1];
			}
		}
	}

	for (int i = 0; i < c; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}