#include <iostream>

using namespace std;

int* createArray(int n, int max, int min)
{
	srand(time(0));
	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % max + min;

		cout << a[i] << " ";
	}

	cout << endl << endl;

	return a;
}


void shellSort(int* arr, int n)
{
	for (int h = n / 2; h > 0; h /= 2)
	{
		for (int i = h; i < n; i++)
		{
			int tmp = arr[i];
			int j;

			for (j = i; j >= h && arr[j - h] > tmp; j -= h)
			{
				arr[j] = arr[j - h];
			}

			arr[j] = tmp;
		}

		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl << endl;
	}
}

int main()
{
	int n = 0, max = -1, min = -1;

	while (n <= 0)
	{
		cout << "Enter number of elements" << endl;
		cin >> n;
	}

	while (max < 0)
	{
		cout << "Enter maximum value (>= 0)" << endl;
		cin >> max;
	}

	while (min < 0)
	{
		cout << "Enter minimum value (>= 0)" << endl;
		cin >> min;
	}

	int* arr = createArray(n, max, min);
	shellSort(arr, n);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}