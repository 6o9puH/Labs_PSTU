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


int partition(int* arr, int low, int high)
{
	int pivot = arr[low];
	int num = 0;

	for (int i = low + 1; i <= high; i++)
	{
		if (arr[i] < pivot)
		{
			num++;
		}
	}

	int pos = low + num;

	swap(arr[pos], arr[low]);

	int i = low, j = high;
	while (i < pos && j > pos)
	{
		while (arr[i] < pivot) 
		{
			i++;
		}

		while (arr[j] > pivot) 
		{
			j--;
		}

		if (i < pos && j > pos)
		{
			swap(arr[i++], arr[j--]);
		}
	}

	return pos;
}

void quickSort(int* arr, int low, int high)
{
	if (low >= high) 
	{
		return ;
	}

	int pI = partition(arr, low, high);
	quickSort(arr, low, pI - 1);
	quickSort(arr, pI + 1, high);
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
	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}