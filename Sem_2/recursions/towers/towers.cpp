#include <iostream>

using namespace std;

void f(int n, int a, int z)
{
	if (n == 1)
	{
		cout << a << " >> " << z << endl;
	}
	else
	{
		f(n - 1, a, 6 - a - z);

		cout << a << " >> " << z << endl;

		f(n - 1, 6 - a - z, z);
	}
}

int main()
{
	int n;

	cin >> n;

	f(n, 1, 2);

	return 0;
}