#include <iostream> <cmath>

using namespace std;

int main()
{
	float a, b;
	float * ptr1 = &a;
	float * ptr2 = &b;

	cin >> a >> b;

	cout << * ptr1 + * ptr2;

	return 0;
}