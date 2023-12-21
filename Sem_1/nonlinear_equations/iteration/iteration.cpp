// f(x) = 3*sin(sqrt(x)) + 0.35*x - 3.8
// f'(x) = 3*cos(sqrt(x))*1/(2*sqrt(x))+0.35 
// f''(x) = (3*sin(sqrt(x))*sqrt(x)+3*cos(sqrt(x)))/(4*x*sqrt(x))
// [2; 3]


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x = 2;
    float xprev = 0;
    double eps = 0.000001;

    while (abs(x - xprev) > eps)
    {
        xprev = x;
        x = (3.8 - 3*sin(sqrt(xprev)))/0.35;
    }
    cout << x;
    return 0;
}