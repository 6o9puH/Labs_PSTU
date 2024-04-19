#include <iostream>
#include <string>

using namespace std;

void knuthMorrisPrattSearch(string str)
{
    bool f = false;
    string pat;

    cout << "Enter pattern\n";
    getline(cin, pat);
    
    int* a = new int[pat.size()];

    for (int i = 0; i < pat.size(); i++)
    {
        int j = 0;

        while (j < i)
        {
            bool f = true;
            int k = 0;

            while (f = true and k <= j)
            {
                if (pat[k] != pat[i - j + k])
                {
                    f = false;
                }
                k++;
            }

            j++;

            if (f == true)
            {
                a[i] = j;
            }
        }
    }

    int i = 0;

    while (i <= str.size() - pat.size())
    {
        int j = 0;

        while (j < pat.size() and pat[j] == str[i + j])
        {
            j++;
        }

        if (j == pat.size())
        {
            cout << i + 1 << " ";
            f = true;
            i++;
        }
        else
        {
            int cur = i + j;

            while (j >= 0 and pat[j] != str[cur])
            {
                if (j == 0)
                {
                    j--;
                    i = cur + 1;
                }
                else
                {
                    j = a[j - 1];
                }
            }

            if (j < 0)
            {
                i = cur + 1;
            }
            else
            {
                i += j + 1;
            }
        }
    }

    delete[] a;

    if (f == false)
    {
        cout << "Element not found";
    }

    cout << endl << "!!!!! !!!!! !!!!! !!!!! !!!!!" << endl;

    knuthMorrisPrattSearch(str);
}


int main()
{
    string str;

    cout << "Enter the string\n";

    getline(cin, str);
    knuthMorrisPrattSearch(str);

	return 0;
}