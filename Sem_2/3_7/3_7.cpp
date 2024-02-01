#include <iostream>

using namespace std;

int main()
{
	const int c = 10;
	int mx = 0, mn = 0, a[c] = { 1,2,3,4,5,6,7,8,9,0 };

	for (int i = 0; i < c; i++)
	{
		if ((a[i] > mx) or (i == 0))
		{
			mx = a[i];
		}

		if ((a[i] < mn) or (i == 0))
		{
			mn = a[i];
		}
	}

	cout << mx << endl << mn;

	return 0;
}