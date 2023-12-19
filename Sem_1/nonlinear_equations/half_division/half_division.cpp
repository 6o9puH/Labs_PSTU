// 3*sin(sqrt(x)) + 0.35*x - 3.8 = 0
// [2; 3]

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c;
    float fA, fB, fC;
    double eps = 0.000001;

    a = 2;
    b = 3;

    while (b - a > eps)
    {
        c = (a + b) / 2;
        fA = 3 * sin(sqrt(a)) + 0.35 * a - 3.8;
        fB = 3 * sin(sqrt(b)) + 0.35 * b - 3.8;
        fC = 3 * sin(sqrt(c)) + 0.35 * c - 3.8;
        if (fA * fC < 0) { b = c; }
        else if (fC * fB < 0) { a = c; }
        else { cout << "Что-то не то!" << endl; }
    }
    cout << "Корни: " << a << "; " << b << endl;
    return 0;
}