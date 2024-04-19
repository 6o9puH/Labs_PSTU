#include <iostream>
#include <string>

using namespace std;

void boyerMooreSearch(string str)
{
    bool f = false;
    string pat;

    cout << "Enter pattern\n";
    getline(cin, pat);
    
    int i = 0;

    while (i <= str.size() - pat.size())
    {
        int j = pat.size() - 1;

        while (j >= 0 and pat[j] != str[i + pat.size() - 1])
        {
            j--;
        }
            
        if (j == pat.size() - 1)
        {
            while (j >= 0 and pat[j] == str[i + j])
            {
                if (j == 0)
                {
                    cout << i + 1 << " ";
                    f = true;
                }

                j--;
            }

            if (j >= 0)
            {
                j = pat.size() - 2;

                while (j >= 0 and pat[j] != str[i + pat.size() - 1])
                {
                    j--;
                }
            }
        }

        i += pat.size() - 1 - j;
    }

    if (f == false)
    {
        cout << "Element not found";
    }

    cout << endl << "!!!!! !!!!! !!!!! !!!!! !!!!!" << endl;

    boyerMooreSearch(str);
}


int main()
{
    string str;

    cout << "Enter the string\n";

    getline(cin, str);
    boyerMooreSearch(str);

	return 0;
}