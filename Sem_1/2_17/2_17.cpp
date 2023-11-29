#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    float x, fact, sum;

    cin >> n >> x;

    sum = 1 + x;
    fact = 1;

    for (int i = 2; i <= n; i++)
    {
        fact *= i;
        sum += (pow(x, i) / fact);
    }
    cout << sum << endl;

	return 0;
}