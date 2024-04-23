#include "Book.h"
#include <iostream>

using namespace std;

Book make_book()
{
	string N, A;
	int Y;

	cout << "Enter name:\n";
	cin >> N;
	cout << "Enter the author";
	cin >> A;
	cout << "Enter year";
	cin >> Y;

	Book b(N, A, Y);

	return b;
}

void print_book(Book b)
{
	b.show();
}

void main()
{
	Book b1;
	b1.show();
	Book b2("A", "B", -1);
	b2.show();
	Book b3 = b2;
	b3.set_name("0");
	b3.set_author("1");
	b3.set_year(1);
	print_book(b3);
	b1 = make_book();
	b1.show();
}