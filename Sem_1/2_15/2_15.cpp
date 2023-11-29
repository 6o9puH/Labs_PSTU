#include <iostream>

using namespace std;

int main()
{
	int s;
	int f = 1;

	cin >> s;

	while (s != 0)
	{
		if (s % 10 != 5)
		{
			f = 1;
		}
		s /= 10;
	}

	if (f == 1)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}

	return 0;
}