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


void merge(int* arr, int left, int mid, int right)
{
    int leftRange = mid - left + 1;
    int rightRange = right - mid;

    int* leftArr = new int[leftRange];
    int* rightArr = new int[rightRange];

    for (int i = 0; i < leftRange; i++)
    {
        leftArr[i] = arr[left + i];

        cout << leftArr[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < rightRange; i++)
    {
        rightArr[i] = arr[mid + 1 + i];

        cout << rightArr[i] << " ";
    }

    cout << endl;

    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = left;

    while (leftIndex < leftRange && rightIndex < rightRange)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergeIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    while (leftIndex < leftRange)
    {
        arr[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    while (rightIndex < rightRange)
    {
        arr[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;

    for (int i = 0; i < mergeIndex; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


void mergeSort(int* arr, int start, int end)
{
    if (start >= end) 
    {
        return ;
    }
	int mid = (start + end)/ 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
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
	int l = 0, r = n - 1;
    if (l >= r) 
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        return 0;
    }
	int mid = (l + r) / 2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	merge(arr, l, mid, r);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

	return 0;
}