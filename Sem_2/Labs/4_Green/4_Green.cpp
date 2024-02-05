#include <iostream> <stdio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	const int N = 100;
	int n = -1, a[N];

	while ((n < 0) or (n > N / 2))
	{
		cout << "Введите размер массива, меньший, чем " << N / 2 + 1 << endl;
		cin >> n;
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;

		cout << a[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			for (int j = i; j < n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (int j = n + 1; j > i + 1; j--)
			{
				a[j] = a[j - 1];
			}

			a[i + 1] = a[i] + 2;
			i++;
			n++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}