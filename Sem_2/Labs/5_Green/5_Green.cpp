#include <iostream>

using namespace std;

void s(int y1, int y2, int a[10][10])
{
	int ta[10];

	for (int i = 0; i < 10; i++)
	{
		ta[i] = a[y1][i];
	}

	for (int i = 0; i < 10; i++)
	{
		a[y1][i] = a[y2][i];
		a[y2][i] = ta[i];
	}
}

int main()
{
	srand(time(NULL));

	int a[10][10];

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			a[y][x] = rand() % 10;

			cout << a[y][x] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 1; i < 10; i++)
	{
		for (int j = i; (j > 0) and (a[j - 1][2] > a[j][2]); j--)
		{
			s(j, j - 1, a);
		}
	}

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << a[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}