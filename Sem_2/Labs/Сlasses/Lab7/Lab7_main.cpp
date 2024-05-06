#include "Vector.h"
#include "Time.h"
#include <iostream>

using namespace std;

void main()
{
	Vector<int> A(5, 0);

	cout << "Enter A:\n";
	cin >> A;
	cout << "A:\n" << A << endl;

	Vector<int> B(10, 1);

	cout << "B:\n" << B << endl;

	B = A;

	cout << "B:\n" << B << endl;
	cout << "A[2]: " << A[2] << endl;
	cout << "size of A: " << A() << endl;

	B = A + A;

	cout << "B = A + A =\n" << B << endl;

	Time t;

	cout << "Enter T:\n";
	cin >> t;
	cout << "T:\n" << t << endl;

	Time k;

	cout << "Enter K:\n";
	cin >> k;

	Time p;
	p = t + k;

	cout << "P = T + K = " << p << "\nEnter T:\n";
	cin >> t;
	cout << "T:\n" << t << endl;

	Vector<Time>C(5, t);

	cout << "Enter C:\n";
	cin >> C;
	cout << "C:\n" << C << endl;

	Vector<Time>D(10, t);
	cout << "D:\n" << D << endl;

	D = C;

	cout << "D:\n" << D << endl;
	cout << "C[2]:\n" << C[2] << endl;
	cout << "size of C = " << C() << endl;

	D = C + C;

	cout << "D = C + C =\n" << D << endl;
}