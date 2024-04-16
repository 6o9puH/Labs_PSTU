#include <iostream>

using namespace std;

struct arr
{
	int* a;
	int size;
};

int* createArray(int size)
{
	srand(time(0));
	int* a = new int[size];
	int min = 0;

	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 10 + min;
			
		cout << a[i] << " ";
		
		min = a[i] + 1;
	}

	cout << endl << endl;

	return a;
}


void interpolationSearch(arr a) 
{
	int key;
	bool f = false;

	cout << "Enter key" << endl;
	cin >> key;

	int mid;
	int low = 0;
	int high = a.size - 1;

	while (a.a[low] < key && a.a[high] > key) 
	{
		if (a.a[high] == a.a[low])
		{
			break;
		}

		mid = low + ((key - a.a[low]) * (high - low)) / (a.a[high] - a.a[low]);

		if (a.a[mid] < key)
		{
			low = mid + 1;
		}
		else if (a.a[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			cout << mid + 1;

			f = true;

			break;
		}
	}

	if (a.a[low] == key)
	{
		cout << low + 1;

		f = true;
	}
	else if (a.a[high] == key)
	{
		cout << high + 1;

		f = true;
	}

	if (f == false)
	{
		cout << "Element not found";
	}

	cout << endl << "!!!!! !!!!! !!!!! !!!!! !!!!!" << endl;

	interpolationSearch(a);
}


int main()
{
	int n = 0, max = -1, min = -1, key;
	arr a;

	while (n <= 0)
	{
		cout << "Enter number of elements" << endl;
		cin >> n;
	}

	a.a = createArray(n);
	a.size = n;
	interpolationSearch(a);

	return 0;
}