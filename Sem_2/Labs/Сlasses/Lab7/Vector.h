#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector
{
public:
	Vector(int s, T k)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = k;
		}
	}

	Vector(const Vector<T>&a)
	{
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
	}

	~Vector()
	{
		delete[] data;
		data = 0;
	}

	Vector& operator=(const Vector<T>&a)
	{
		if (this == &a)
		{
			return *this;
		}
		
		size = a.size;

		if (data != 0)
		{
			delete[] data;
		}

		data = new T[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}

		return *this;
	}

	T& operator[](int index)
	{
		if (index < size)
		{
			return data[index];
		}
		else
		{
			cout << "Error! Index > size\n";
		}
	}

	Vector operator+(const Vector<T>&a)
	{
		int m;
		
		if (a.size < size)
		{
			m = a.size;
		}
		else
		{
			m = size;
		}

		Vector temp(m, T());

		for (int i = 0; i < m; ++i)
		{
			temp.data[i] = data[i] + a.data[i];
		}

		return temp;
	}

	int operator()()
	{
		return size;
	}

	friend ostream& operator<<(ostream& out, const Vector<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
		{
			out << a.data[i] << " ";
		}

		return out;
	}

	friend istream& operator>>(istream& in, Vector<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
			in >> a.data[i];
		return in;
	}
private:
	int size;
	T* data;
};