#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int k = 0;
	bool l = false;
	string s;
	ifstream f1("L9F1.txt");
	ofstream f2("L9F2.txt");

	while (getline(f1, s))
	{
		if (tolower(s[0]) == 'a')
		{
			f2 << s << endl;
		}
	}

	f1.close();
	ifstream f3 ("L9F2.txt");

	while (getline(f3, s))
	{
		for (int i = 0; i < s.length(); i++)
		{
			if ((s[i] == ' ' and l == true) or (i == s.length() - 1 and s[i] != ' '))
			{
				k++;
				l = false;
				continue;
			}
			l = true;
		}
	}

	f3.close();

	cout << "words: " << k;

	return 0;
}