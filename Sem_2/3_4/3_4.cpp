#include <iostream>

using namespace std;

int main()
{
	const int c = 10;
	int a[c] = {1,2,3,4,5,6,7,8,9,0};
	bool fl = 1;
	
	for (int i = 0; i < c - 1; i++)
	{
		if (a[i] >= a[i + 1])
		{
			fl = 0;
			break;
		}
	}

	if (fl == 1)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}

	return 0;
}