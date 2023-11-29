#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float n, s, a;
    int i = 1;
    bool flag = false;

    cin >> n >> s;

    while (i <= n && !flag)
    {
        a = sin(n + i / n);
        a = round(a * 10) / 10;
        cout << n + i / n << "|" << a << endl;

        if (a == s)
        {
            flag = true;
        }
        else
        {
            i++;
        }
    }
    
    if (flag)
    {
        cout << "Элемент найден!" << endl;
    }
    else
    {
        cout << "Элемент не найден!" << endl;
    }

	return 0;
}