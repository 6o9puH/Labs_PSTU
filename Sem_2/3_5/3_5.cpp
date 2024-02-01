#include <iostream>

using namespace std;

int main()
{
	const int c = 10;
	int m = 0, a[c];

	for (int i = 0; i < c; i++)
	{
		a[i] = rand() % 100;

		if ((a[i] > m) or (i == 0))
		{
			m = a[i];
		}

		cout << a[i] << endl;
	}

	cout << endl << m;

	return 0;
}