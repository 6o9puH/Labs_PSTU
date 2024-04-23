#include "money.h"
#include <iostream>

using namespace std;

fraction make_fraction(int F, int S)
{
	if ((F != 1) and (F != 2) and (F != 5) and (F != 10) and (F != 50) and (F != 500) and (F != 1000) and (F != 5000)
		or S < 0)
	{
		cout << "Invalid values";
		exit(0);
	}

	fraction t;
	t.Init(F, S);

	return t;
}


int main()
{
	cout << "first = 1/2/5/10/50/100/500/1000/5000;\nsecond >= 0;\n";
	cout << "Definition of variables\n";

	fraction A, B;
	A.Init(1, 5);
	B.Read();
	A.Show();
	B.Show();

	cout << "A.summa(" << A.first << "," << A.second << ") = " << A.summa() << endl;
	cout << "B.summa(" << B.first << "," << B.second << ") = " << B.summa() << endl;
	cout << "Pointer\n";

	fraction* X = new fraction;
	X->Init(5, 1);
	X->Show();
	X->summa();

	cout << "X.summa(" << X->first << "," << X->second << ") = " << X->summa() << endl;
	cout << "Array\n";

	fraction mas[3];

	for (int i = 0; i < 3; i++)
	{
		mas[i].Read();
	}

	for (int i = 0; i < 3; i++)
	{
		mas[i].Show();
	}

	for (int i = 0; i < 3; i++)
	{
		mas[i].summa();

		cout << "mas[" << i << "].summa(" << mas[i].first << ", " << mas[i].second << ") = " << mas[i].summa() << endl;
	}
	
	cout << "Dynamic array\n";

	fraction* p_mas = new fraction[3];

	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Read();
	}

	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Show();
	}

	for (int i = 0; i < 3; i++)
	{
		p_mas[i].summa();

		cout << "p_mas[" << i << "].summa(" << p_mas[i].first << ", " << p_mas[i].second << ") = " << p_mas[i].summa() << endl;
	}
	

	cout << "Function make_fraction\n";

	int y, z;

	cout << "Enter first\n";
	cin >> y;
	cout << "Enter second\n";
	cin >> z;

	fraction F = make_fraction(y, z);
	F.Show();

	return 0;
}