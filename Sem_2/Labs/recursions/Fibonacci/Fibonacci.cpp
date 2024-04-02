#include <iostream>

using namespace std;

int f(int x)
{
	switch (x)
	{
	case 1: return 0; break;

	case 2: return 1; break;

	default: return f(x - 1) + f(x - 2);
	}
}

int main()
{
	int x;

	cin >> x;
	cout << f(x);

	return 0;
}