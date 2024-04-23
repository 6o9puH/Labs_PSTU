#include "Book.h"
#include <iostream>

using namespace std;

Book::Book()
{
	name = "";
	author = "";
	year = 0;

	cout << "Constructor without parameters" << this << endl;
}

Book::Book(string N, string A, int Y)
{
	name = N;
	author = A;
	year = Y;

	cout << "Constructor with parameters" << this << endl;
}

Book::Book(const Book& b)
{
	name = b.name;
	author = b.author;
	year = b.year;

	cout << "Copy constructor " << this << endl;
}

Book::~Book()
{
	cout << "Destructor" << this << endl;
}

string Book::get_name()
{
	return name;
}

string Book::get_author()
{
	return author;
}

int Book::get_year()
{
	return year;
}

void Book::set_name(string N)
{
	name = N;
}

void Book::set_author(string A)
{
	author = A;
}

void Book::set_year(int Y)
{
	year = Y;
}

void Book::show()
{
	cout << "Name: " << name;
	cout << "\nAuthor: " << author;
	cout << "\nYear: " << year << endl;
}