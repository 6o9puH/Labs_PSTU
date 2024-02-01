#include <iostream>

using namespace std;

int main()
{
	const int c = 10;
	int m = 0, k, a[c] = { 1,2,3,4,5,6,7,8,9,0 };

	for (int i = 0; i < c; i++)
	{
		if ((i != 0) and (a[i] == m))
		{
			k++;
		}
		if ((a[i] > m) or (i == 0))
		{
			m = a[i];
			k = 1;
		}
	}

	cout << m << endl << k;

	return 0;
}