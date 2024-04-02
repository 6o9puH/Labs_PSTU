#include <iostream>

using namespace std;

int main()
{
	const int N = 10;
	int a[N][N];
	int s = 1;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if ((x + y) % 2 == 1)
			{
				a[y][x] = 0;
			}
			else
			{
				a[y][x] = s;
				s++;
				if (s == 10)
				{
					s = 1;
				}
			}
			cout << a[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}