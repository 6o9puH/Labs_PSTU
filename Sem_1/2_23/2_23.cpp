#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a;
	float max = -1;
	int n, k;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		a = sin(n + i / n);
		if (max < a)
		{
			max = a;
			k = 0;
		}

		if (max == a)
		{
			k++;
		}
	}

	cout << k;
	
	return 0;
}