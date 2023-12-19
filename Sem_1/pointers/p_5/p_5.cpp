#include <iostream> <cmath>

using namespace std;

int main()
{
	int n;
	int s = 0;
	int t = 1;
	int* ps = &s;
	int* pt = &t;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		*pt *= i;
		*ps += *pt;
	}

	cout << *ps;

	return 0;
}