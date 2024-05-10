#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Time t;
	cout << "N?\n";  cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		stream << t << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t;
	int i = 0;
	while (stream >> t)
	{
		cout << t;
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0;
	Time t;
	while (stream >> t)
	{
		if (stream.eof()) break;
		if (i != k) temp << t; 
		i++;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, int k, Time tt)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t;
	int i = 0, l = 0;
	while (stream >> t)
	{
		if (stream.eof()) break;
		if (i == k)
		{
			temp << tt;
			l++;
		}
		temp << t;
		i++;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return 1;
}

int add_end(const char* f_name, Time tt)
{
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	stream << tt;
	return 1;
}

int change_file(const char* f_name, int k, Time tt)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t;
	int i = 0, l = 0;
	char x;
	while (stream >> t)
	{
		if (stream.eof())break;
		i++;
		if (i == k)
		{
			cout << t << " - is changing... Continue [y/n]?\n";
			cin >> x;
			if (x == 'n' || x == 'N') break;
			else
			{
				temp << tt;
				l++;
			}
		}
		else temp << t;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int del_exept(const char* f_name, Time e)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t;
	int i = 0;
	while (stream >> t)
	{
		if (stream.eof()) break;
		if (!(t != e)) temp << t;
		i++;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int decrease(const char* f_name, Time e)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time d(1, 30);
	if (e < d) return -2;
	Time t;
	int i = 0;
	while (stream >> t)
	{
		if (stream.eof()) break;
		if (!(t != e)) temp << t - d;
		else temp << t;
		i++;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_b(const char* f_name, int x)
{
	if (x < 0) return -2;
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t;
	for (int i = 0; i < x; i++)
	{
		cin >> t;
		temp << t;
	}
	while (stream >> t)
	{
		if (stream.eof()) break;
		temp << t;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return 1;
}