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


void binarySearch(arr a)
{
	int key;
	bool f = false;

	cout << "Enter key" << endl;
	cin >> key;

	int left = 0;
	int right = a.size - 1;

	while (left <= right) 
	{
		int mid = left + (right - left) / 2;

		if (a.a[mid] == key)
		{
			cout << mid + 1;
			f = true;
			break;
		}
		else if (a.a[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	if (f == false)
	{
		cout << "Element not found";
	}

	cout << endl << "!!!!! !!!!! !!!!! !!!!! !!!!!" << endl;

	binarySearch(a);
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

	binarySearch(a);

	return 0;
}