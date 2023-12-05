#include <iostream>

using namespace std;

int main()
{
	int i1;
	int i2 = 1;
	int f = 1;

	cin >> i1 >> i2;

	if (i1 >= i2)
	{
		f = 0;
	}

	i1 = i2;

	cin >> i2;

	while (i2 != 0)
	{
		if (i1 >= i2)
		{
			f = 0;
		}

		i1 = i2;

		cin >> i2;
	}

	if (f == 1)
	{
		cout << "числа упорядочены";
	}

	else
	{
		cout << "числа не упорядочены";
	}
	
	return 0;
}