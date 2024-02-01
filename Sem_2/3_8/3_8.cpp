#include <iostream>

using namespace std;

int main()
{
	const int c = 10;
	int k = 0, a[c], n = c;

	for (int i = 0; i < c / 2; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < n / 2; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = n - 1; j > i - 1; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = -1;
			i++;
			n++;
			k++;
		}
	}

	for (int i = 0; i < c / 2 + k; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}