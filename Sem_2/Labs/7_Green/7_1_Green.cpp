//Написать перегруженные функции и основную программу, которая их вызывает. 
//2. а) для сложения вещественных чисел; б) для сложения комплексных чисел.

#include <iostream> 
#include <complex>

using namespace std;

float sum(float a, float b)
{
	return a + b;
}

complex <double> sum(complex <double> x, complex <double> y)
{
	return x + y;
}

int main()
{
	float  a, b;
	complex<double> x, y;

	cout << "Enter float numbers" << endl;
	cin >> a >> b;
	cout << "Sum of float numbers: " << sum(a, b) << endl;
	cout << "Enter complex numbers" << endl;
	cin >> x >> y;
	cout << "Sum of complex numbers: " << sum(x, y) << endl;

	return 0;
}