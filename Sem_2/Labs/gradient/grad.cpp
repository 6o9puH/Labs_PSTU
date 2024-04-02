#include <iostream>

using namespace std;

int main()
{
	const int N = 9;
	int a[N][N];

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (y < x)
			{
				a[y][x] = 0;
			}
			else
			{
				for (int i = 1; i <= N; i++)
				{
					if (y == x - 1 + i)
					{
						a[y][x] = i;
						break;
					}
				}
			}
			cout << a[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}