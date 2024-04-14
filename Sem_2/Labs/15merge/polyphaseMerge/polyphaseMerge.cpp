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


int* merge(int* arr1, int a1size, int* arr2, int a2size, int* out)
{
	cout << "a) ";

	for (int i = 0; i < a1size; i++)
	{
		cout << arr1[i] << " ";
	}

	cout << endl << "b) ";

	for (int i = 0; i < a2size; i++)
	{
		cout << arr2[i] << " ";
	}

	cout << endl << "c) ";

	int i1 = 0, i2 = 0, io = 0;
	int osize = 0;

	while (i2 < a2size)
	{
		int j1 = i1, j2 = i2;

		while ((i1 == j1 or arr1[i1] >= arr1[i1 - 1])
			and (i2 == j2 or arr2[i2] >= arr2[i2 - 1])
			and (i1 < a1size and i2 < a2size))
		{
			if (arr1[i1] <= arr2[i2])
			{
				out[io++] = arr1[i1++];
				osize++;
			}
			else
			{
				out[io++] = arr2[i2++];
				osize++;
			}
		}

		while ((i1 == j1 or arr1[i1] >= arr1[i1 - 1]) and i1 < a1size)
		{
			out[io++] = arr1[i1++];
			osize++;
		}

		while ((i2 == j2 or arr2[i2] >= arr2[i2 - 1]) and i2 < a2size)
		{
			out[io++] = arr2[i2++];
			osize++;
		}
	}

	int a1i = 0;

	for (int i = i1; i < a1size; i++)
	{
		arr1[a1i] = arr1[i];
		a1i++;
	}

	a1size = a1i;

	for (int i = 0; i < osize; i++)
	{
		cout << out[i] << " ";
	}

	cout << endl << endl;

	if (a1size == 0)
	{
		return out;
	}
	else
	{
		return merge(out, osize, arr1, a1size, arr2);
	}
}


int* polyphaseMerge(int* arr, int size)
{
	int count = 1;

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			count++;
		}
	}

	if (count == 1)
	{
		return arr;
	}

	int fib0 = 0;
	int fib1 = 1;

	while (count > fib1)
	{
		int tmp = fib1;
		fib1 = fib0 + fib1;
		fib0 = tmp;
	}
	
	int* a = new int[size];
	int* b = new int[size];
	int* c = new int[size];
	int ia = 0, ib = 0, ic = 0, cnt = 0;
	int asize = 0, bsize = 0, csize = 0;

	for (int i = 0; i < size - 1; i++)
	{
		if (cnt < fib0)
		{
			a[ia++] = arr[i];
			asize++;
		}
		else
		{
			b[ib++] = arr[i];
			bsize++;
		}
		
		if (arr[i] > arr[i + 1])
		{
			cnt++;
		}
	}


	b[ib] = arr[size - 1];
	bsize++;

	cout << "a) ";

	for (int i = 0; i < asize; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl << "b) ";

	for (int i = 0; i < bsize; i++)
	{
		cout << b[i] << " ";
	}

	cout << endl << "c) ";

	ia = 0;
	ib = 0;

	for (int cnt = 0; cnt < fib1 - fib0; cnt++)
	{
		int ja = ia, jb = ib;

		while ((ia == ja or a[ia] >= a[ia - 1]) 
			and (ib == jb or b[ib] >= b[ib - 1])
			and (ia < asize and ib < bsize))
		{
			if (a[ia] <= b[ib])
			{
				c[ic++] = a[ia++];
				csize++;
			}
			else
			{
				c[ic++] = b[ib++];
				csize++;
			}
		}

		while ((ia == ja or a[ia] >= a[ia - 1]) and ia < asize)
		{
			c[ic++] = a[ia++];
			csize++;
		}

		while ((ib == jb or b[ib] >= b[ib - 1]) and ib < bsize)
		{
			c[ic++] = b[ib++];
			csize++;
		}
	}

	int ai = 0;

	for (int i = ia; i < asize; i++)
	{
		a[ai] = a[i];
		ai++;
	}

	asize = ai;

	for (int i = 0; i < csize; i++)
	{
		cout << c[i] << " ";
	}

	cout << endl << endl;

	if (asize == 0)
	{
		return c;
	}
	else
	{
		return merge(c, csize, a, asize, b);
	}

	delete[] a;
	delete[] b;
	delete[] c;
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
	arr = polyphaseMerge(arr, n);

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}