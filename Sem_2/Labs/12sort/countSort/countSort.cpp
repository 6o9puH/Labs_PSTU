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


int* countSort(int* a, int size)
{
	int* output = new int[size];
	int max = a[0];

	for (int i = 0; i < size; i++)
	{
		if (a[i] > max) 
		{
			max = a[i];
		}
	}

	int* count = new int[max + 1];

	for (int i = 0; i <= max; ++i) 
	{
		count[i] = 0;
	}

	cout << "count array: ";

	for (int i = 0; i < size; i++) 
	{
		count[a[i]]++;
	}

	for (int i = 0; i <= max; i++)
	{
		cout << count[i] << " ";
	}

	cout << endl << endl;

	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}

	cout << "count array: ";

	for (int i = 0; i <= max; i++)
	{
		cout << count[i] << " ";
	}

	cout << endl << endl;

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < size; i++) 
	{
		a[i] = output[i];
	}

	delete[] count;
	delete[] output;

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	return a;
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
	arr = countSort(arr, n);

	return 0;
}