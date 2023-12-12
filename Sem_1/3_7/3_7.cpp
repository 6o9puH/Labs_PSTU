#include <iostream>

using namespace std;

int main()
{
    int a;
    int* p = &a;

    cin >> a >> *p;
    cout << *p;

    return 0;
}