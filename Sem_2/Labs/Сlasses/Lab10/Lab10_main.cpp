#include "Time.h"
#include <iostream>
#include <fstream>
#include "file_work.h"

using namespace std;

void main()
{
	Time t, t1, t2, e;
	int k, c;
	char file_name[30];
	do
	{
		cout << "1.Make file\n";
		cout << "2.Print file\n";
		cout << "3.Delete record from file\n";
		cout << "4.Add record to file\n";
		cout << "5.Change record in file\n";
		cout << "6.Delete all exept X\n";
		cout << "7.Decrease all X by 1:30\n";
		cout << "8.Add X entries to the beginning\n";
		cout << "0.Exit\n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "file name?\n"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "Can't make file\n";
			k = print_file(file_name);
			if (k == 0) cout << "Emty file\n";
			break;
		case 2:
			cout << "file name?\n"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0) cout << "Emty file\n";
			if (k < 0) cout << "Can't read file\n";
			break;
		case 3:
			cout << "file name?\n"; cin >> file_name;
			int nom;
			cout << "nom?\n";
			cin >> nom;
			k = del_file(file_name, nom);
			if (k < 0) cout << "Can't read file\n";
			k = print_file(file_name);
			if (k == 0) cout << "Emty file\n";
			break;
		case 4:
			cout << "file name?\n"; cin >> file_name;
			cout << "nom?\n";
			cin >> nom;
			cout << "New time: \n";
			cin >> t1;
			k = add_file(file_name, nom, t1);
			if (k < 0) cout << "Can't read file\n";
			if (k == 0) k = add_end(file_name, t1);
			k = print_file(file_name);
			if (k == 0) cout << "Emty file\n";
			break;
		case 5:
			cout << "file name?\n"; cin >> file_name;
			cout << "nom?\n";
			cin >> nom;
			cout << "New time: \n";
			cin >> t2;
			k = change_file(file_name, nom, t2);
			if (k < 0) cout << "Can't read file\n";
			if (k == 0) cout << "Not such record\n";
			k = print_file(file_name);
			if (k == 0) cout << "Emty file\n";
			break;
		case 6:
			cout << "file name?\n"; cin >> file_name;
			cout << ">"; cin >> e;
			k = del_exept(file_name, e);
			if (k < 0) cout << "Can't read file\n";
			k = print_file(file_name);
			if (k == 0) cout << "Emty file\n";
			break;
		case 7:
			cout << "file name?\n"; cin >> file_name;
			cout << ">"; cin >> e;
			k = decrease(file_name, e);
			if (k == -1) cout << "Can't read file\n";
			if (k == -2) cout << "Interval less than 0\n";
			k = print_file(file_name);
			if (k == 0) cout << "Emty file\n";
			break;
		case 8:
			cout << "file name?\n"; cin >> file_name;
			int x;
			cout << ">"; cin >> x;
			k = add_b(file_name, x);
			if (k == -1) cout << "Can't read file\n";
			if (k == -2) cout << "Wrong number X\n";
			k = print_file(file_name);
			if (k == 0) cout << "Emty file\n";
		}
	} while (c != 0);
}