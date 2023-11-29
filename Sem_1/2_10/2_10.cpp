#include <iostream>

using namespace std;

int main()
{
	int n, a;
	int max = 0;
	int min = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if ((min == -1) or (a > min)
		{
			min = a;
		}
		if (a > max)
		{
			max = a;
		}
	}

	cout << (max + min) << endl;

	return 0;
}