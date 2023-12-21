#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cA, ca, others, total;
    cA = ca = others = total = 0;
    string s;
    char A, a;

    cin >> s;
    cin >> A;
    cin >> a;

    const char* ptr = s.c_str();

    for (int i = 0; i < s.length(); i++)
    {
        if (*ptr == A)
        { 
            cA++; 
        }
        else if (*ptr == a)
        { 
            ca++;
        }
        else 
        { 
            others++;
        }

        ptr++;

    }

    total = cA + ca + others;

    cout << A << " : " << cA << endl << a << " : " << ca << endl << "others : " << others << endl << "total : " << total;

    return 0;
}