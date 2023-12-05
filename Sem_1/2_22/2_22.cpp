#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a;
	float max = -1;
	int n, num;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		a = sin(n + i / n);
			if (max < a)
			{
				max = a;
				num = i;
			}
	}

	cout << max << endl << num;

		return 0;
}