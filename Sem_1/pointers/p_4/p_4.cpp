#include <iostream> <cmath>

using namespace std;

int main()
{
	int n, min, max, a;
	int* ptr = &a;
	int* pmax = &max;
	int* pmin = &min;

	cin >> n >> a;

	*pmax = *ptr;
	*pmin = *ptr;

	for (int i = 1; i < n; i++)
	{
		cin >> a;

		if (*ptr > *pmax)
		{
			*pmax = *ptr;
		}

		if (*ptr < *pmin)
		{
			*pmin = *ptr;
		}
	}

	cout << *pmax << endl << *pmin;

	return 0;
}