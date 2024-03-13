#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct employee
{
	char name0[100];
	char name1[100];
	char name2[100];
	char job[100];
	int year;
	int salary;

	void printer()
	{
		cout << "Full name: " << name0 << " " << name1 << " " << name2 << endl;
		cout << "Job: " << job << endl;
		cout << "Year of birth: " << year << endl;
		cout << "Salary: " << salary << endl << endl;
	}

	void reader()
	{
		cout << "Enter full name (in three lines: surname, name, middlename)" << endl;
		cin >> name0 >> name1 >> name2;
		cout << "Enter job" << endl;
		cin >> job;
		cout << "Enter year of birth" << endl;
		cin >> year;
		cout << "Enter salary" << endl;
		cin >> salary;
		cout << endl;
	}
};

int deleter(char surname[100], int n)
{
	int c = 0;
	employee tmp;
	FILE* f;
	FILE* ftmp;

	if ((f = fopen("L8F.bin", "rb")) == NULL) exit(5);
	if ((ftmp = fopen("L8Ftmp.bin", "wb")) == NULL) exit(6);

	for (int i = 0; i < n; i++)
	{
		fread(&tmp, sizeof(employee), 1, f);

		if (strcmp(tmp.name0, surname) != 0)
		{
			fwrite(&tmp, sizeof(employee), 1, ftmp);
			c++;
		}
	}

	fclose(f);
	fclose(ftmp);

	return c;
}

void inserter(int e, int n)
{
	FILE* f;
	FILE* ftmp;
	employee tmp;

	if ((f = fopen("L8F.bin", "wb")) == NULL) exit(7);
	if ((ftmp = fopen("L8Ftmp.bin", "rb")) == NULL) exit(8);
	
	for (int i = 0; i < e; i++)
	{
		fread(&tmp, sizeof(employee), 1, ftmp);
		fwrite(&tmp, sizeof(employee), 1, f);
	}

	tmp.reader();
	fwrite(&tmp, sizeof(employee), 1, f);
	
	for (int i = 0; i < n - e; i++)
	{
		fread(&tmp, sizeof(employee), 1, ftmp);
		fwrite(&tmp, sizeof(employee), 1, f);
	}

	fclose(f);
	fclose(ftmp);
}

int main()
{
	int n, e;
	char surname[100];
	FILE* f;
	employee tmp;

	if ((f = fopen("L8F.bin", "wb")) == NULL) exit(1);

	cout << "Enter the number of elements" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		tmp.reader();
		fwrite(&tmp, sizeof(employee), 1, f);
	}

	fclose(f);

	cout << endl;

	if ((f = fopen("L8F.bin", "rb")) == NULL) exit(2);

	for (int i = 0; i < n; i++)
	{
		fread(&tmp, sizeof(employee), 1, f);
		tmp.printer();
	}

	fclose(f);

	cout << "Enter surname to delete element" << endl;
	cin >> surname;

	n = deleter(surname, n);

	cout << endl;

	if ((f = fopen("L8Ftmp.bin", "rb")) == NULL) exit(3);

	for (int i = 0; i < n; i++)
	{
		fread(&tmp, sizeof(employee), 1, f);
		tmp.printer();
	}

	fclose(f);

	cout << "Enter number to add an element (1;n)" << endl;
	cin >> e;

	inserter(e, n);
	n++;

	cout << endl;

	if ((f = fopen("L8F.bin", "rb")) == NULL) exit(4);

	for (int i = 0; i < n; i++)
	{
		fread(&tmp, sizeof(employee), 1, f);
		tmp.printer();
	}

	fclose(f);

	return 0;
}