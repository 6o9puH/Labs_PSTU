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


int* bucketSort(int* a, int bsize)
{
	int max = a[0], del = 1;
	const int bnum = 10;

	for (int i = 1; i < bsize; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}

	while (max >= 10)
	{
		max /= 10;
		del *= 10;
	}

	int** bucket = new int* [bnum];

	for (int i = 0; i < bnum; i++)
	{
		bucket[i] = new int[bsize];
	}

	int sizes[bnum] = { 0 };

	for (int i = 0; i < bsize; i++)
	{
		int idx = a[i] / del;
		bucket[idx][sizes[idx]++] = a[i];
	}

	for (int i = 0; i < bnum; i++)
	{
		cout << i << ") ";

		for (int j = 0; j < sizes[i]; j++)
		{
			cout << bucket[i][j] << " ";
		}

		cout << endl << endl;
	}

	cout << endl;

	for (int i = 0; i < bnum; i++)
	{
		for (int j = 1; j < sizes[i]; j++)
		{
			int tmp = bucket[i][j];
			int k = j - 1;
			
			while (k >= 0 and bucket[i][k] > tmp)
			{
				bucket[i][k + 1] = bucket[i][k];
				k--;
			}

			bucket[i][k + 1] = tmp;
		}
	}

	for (int i = 0; i < bnum; i++)
	{
		cout << i << ") ";
		
		for (int j = 0; j < sizes[i]; j++)
		{
			cout << bucket[i][j] << " ";
		}

		cout << endl << endl;
	}

	int idx = 0;

	for (int i = 0; i < bnum; i++)
	{
		for (int j = 0; j < sizes[i]; j++)
		{
			a[idx++] = bucket[i][j];
		}
		
		delete[] bucket[i];
	}

	delete[] bucket;

	for (int i = 0; i < bsize; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

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
	arr = bucketSort(arr, n);

	return 0;
}