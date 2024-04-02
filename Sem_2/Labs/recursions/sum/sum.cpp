// 2) S = cos x + cos(2x)/2 + ... + cos(nx)/n
#include <iostream> <cmath>

using namespace std;

float s(int f, int n, float x)
{
	if (n == f)
	{
		return cos(n * x) / n;
	}
	else
	{
		return cos(f * x) / f + s(f + 1, n, x);
	}
}

int main()
{
	int n, x;

	cout << "Enter 'n' and 'x'" << endl;
	cin >> n >> x;
	cout << s(1, n, x);

	return 0;
}