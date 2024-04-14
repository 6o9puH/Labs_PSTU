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


void naturalMerge(int* a, int size)
{
	bool flag = true;
	int i = 0;
	
	while (flag == true and i < size - 1)
	{
		if (a[i] > a[i + 1])
		{
			flag = false;
		}

		i++;
	}

	if (flag == true)
	{
		return;
	}
	
	int* b = new int[size];
	int ib = 0;
	int* c = new int[size];
	int ic = -1;

	for (int i = 0; i < size - 1; i++)
	{
		if (a[i] <= a[i + 1])
		{
			if (flag == false)
			{
				b[ib++] = a[i];
			}
			else
			{
				c[ic++] = a[i];
			}
		}
		else
		{
			if (flag == false)
			{
				b[ib] = a[i];
				flag = true;
				ic++;
			}
			else
			{
				c[ic] = a[i];
				flag = false;
				ib++;
			}
		}
	}

	if (flag == false)
	{
		b[ib] = a[size - 1];
	}
	else
	{
		c[ic] = a[size - 1];
	}

	int bsize = ++ib;
	int csize = ++ic;
	i = ib = ic = 0;

	while (ib < bsize && ic < csize)
	{
		if (b[ib] <= c[ic])
		{
			a[i++] = b[ib++];
		}
		else
		{
			a[i++] = c[ic++];
		}
	}

	while (ib < bsize)
	{
		a[i++] = b[ib++];
	}

	while (ic < csize)
	{
		a[i++] = c[ic++];
	}

	cout << "b)";

	for (int i = 0; i < bsize; i++)
	{
		cout << b[i] << " ";
	}

	cout << endl << "c)";

	for (int i = 0; i < csize; i++)
	{
		cout << c[i] << " ";
	}

	cout << endl << "a)";

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl << endl;

	delete[] b;
	delete[] c;

	naturalMerge(a, size);
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
	naturalMerge(arr, n);

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}