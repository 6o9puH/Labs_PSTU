// f(x) = 3*sin(sqrt(x)) + 0.35*x - 3.8
// f'(x) = 3*cos(sqrt(x))*1/(2*sqrt(x))+0.35 
// f''(x) = (3*sin(sqrt(x))*sqrt(x)+3*cos(sqrt(x)))/(4*x*sqrt(x))
// [2; 3]


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x;
    float xprev = 0;
    double eps = 0.000001;

    if ((3 * sin(sqrt(3)) + 0.35 * 3 - 3.8) * ((3 * sin(sqrt(3)) * sqrt(3) + 3 * cos(sqrt(3))) / (4 * 3 * sqrt(3))) > 0)
    {
        x = 3;
    }
    else if ((3 * sin(sqrt(2)) + 0.35 * 2 - 3.8) * (3 * sin(sqrt(2)) * sqrt(2) + 3 * cos(sqrt(2))) / (4 * 2 * sqrt(2)) > 0)
    {
        x = 2;
    }
    else
    {
        cout << '-';
        return 0;
    }
    
    while (abs(x - xprev) > eps)
    {
        xprev = x;
        x = xprev - (3 * sin(sqrt(xprev)) + 0.35 * xprev - 3.8) / (3 * cos(sqrt(xprev)) * 1 / (2 * sqrt(xprev)) + 0.35);
    }

    cout << x;

    return 0;
}