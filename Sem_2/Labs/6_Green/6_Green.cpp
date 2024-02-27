#include <iostream> 
#include <stdio.h>

using namespace std;

int main()
{
	const int L = 256;
	int l = 0, imn = L, imx = 0;
	char s[L], tmp[L], mn[L], mx[L];

	cout << "Enter the string" << endl;
	gets_s (s);

	for (int i = 0; i < L; i++)
	{
		if (s[i] == ' ' or s[i] == '.')
		{
			if (l < imn and l > 0)
			{
				imn = l;
				for (int j = 0; j < l; j++)
				{
					mn[j] = tmp[j];
				}
			}
			if (l > imx)
			{
				imx = l;
				for (int j = 0; j < l; j++)
				{
					mx[j] = tmp[j];
				}
			}
			l = 0;
			continue;
		}
		tmp[l] = s[i];
		l++;
	}

	cout << "Max word:" << endl;

	for (int i = 0; i < imx; i++)
	{
		cout << mx[i];
	}

	cout << endl << "Min word:" << endl;

	for (int i = 0; i < imn; i++)
	{
		cout << mn[i];
	}

	return 0;
}