#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	int* ptr1 = &a;
	int* ptr2 = &b;
	int* ptr3 = &c;

	cin >> a >> b;

	*ptr3 = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = *ptr3;

	cout << a << endl << b;

	return 0;
}