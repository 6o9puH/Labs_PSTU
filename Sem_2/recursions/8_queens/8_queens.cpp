#include <iostream>

using namespace std;

int board[8][8];
const int Queen = -1;

void resetBoard()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			board[y][x] = 0;
		}
	}
}

void showBoard()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (board[y][x] == Queen)
			{
				cout << "Q ";
			}
			else
			{
				cout << ". ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void setQueen(int x1, int y1)
{
	int d;
	for (int z = 0; z < 8; ++z)
	{
		board[z][x1]++;
		board[y1][z]++;
		d = x1 - y1 + z;

		if (d >= 0 && d < 8)
		{
			board[z][d]++;
		}

		d = x1 + y1 - z;

		if (d >= 0 && d < 8)
		{
			board[z][d]++;
		}
	}
	board[y1][x1] = Queen;
}

void deleteQueen(int x1, int y1)
{
	int d;
	for (int z = 0; z < 8; ++z)
	{
		board[z][x1]--;
		board[y1][z]--;
		d = x1 - y1 + z;

		if (d >= 0 && d < 8)
		{
			board[z][d]--;
		}

		d = x1 + y1 - z;

		if (d >= 0 && d < 8)
		{
			board[z][d]--;
		}
	}
	board[y1][x1] = 0;
}

bool checkQueen(int n)
{
	bool result = false;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (board[y][x] == 0)
			{
				setQueen(x, y);
				if (n == 7)
				{
					result = true;
				}
				else if (!(result = checkQueen(n + 1)))
				{
					deleteQueen(x, y);
				}
			}
		}
	}
	return result;
}

int main()
{
	int x, y, k = 0;
	
	cout << "Enter X and Y (first queen)" << endl;
	cin >> x >> y;

	setQueen(x - 1, y - 1);
	if (checkQueen(1))
	{		
		showBoard();
	}

	return 0;
}