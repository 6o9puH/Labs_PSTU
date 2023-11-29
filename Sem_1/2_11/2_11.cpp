#include <iostream>

using namespace std;

int main()
{
	int n, a;
	int f = -1;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if ((a > 0) and (f == -1))
		{
			f = 1;
		}
		else if ((a < 0) and (f == -1))
		{
			f = 0;
		}
	}

	if (f == 1)
	{
		cout << "положительные" << endl;
	}
	else if (f == 0)
	{
		cout << "отрицательные" << endl;
	}
	else
	{
		cout << "только нули" << endl;
	}

	return 0;
}