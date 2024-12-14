#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void ReflexivitySymmetry(vector<vector<int>> table)
{
    cout << "Рефлексивность: ";

    int number_of_elements = table.size();
    int count = 0;

    for (int i = 0; i < number_of_elements; i++)
    {
        if (table[i][i] == 1)
        {
            count++;
        }
    }

    if (count == 0)
    {
        cout << "Антирефлексивно\n";
    }
    else if (count == number_of_elements)
    {
        cout << "Рефлексивно\n";
    }
    else
    {
        cout << "Частично рефлексивно\n";
    }

    cout << "Симметричность: ";

    bool flag = true;

    for (int y = 0; y < number_of_elements; y++)
    {
        for (int x = y + 1; x < number_of_elements; x++)
        {
            if (table[y][x] != table[x][y])
            {
                flag = false;
                goto breakSymmetryCycle;
            }
        }
    }
    breakSymmetryCycle:

    if (flag)
    {
        cout << "Симметрично\n";
        return;
    }

    flag = true;

    for (int y = 0; y < number_of_elements; y++)
    {
        for (int x = y + 1; x < number_of_elements; x++)
        {
            if (table[y][x] == 1 and table[x][y] == 1)
            {
                flag = false;
                goto breakNoSymmetryCycle;
            }
        }
    }
    breakNoSymmetryCycle:

    if (flag and count == 0)
    {
        cout << "Асимметрично\n";
    }
    else if (flag)
    {
        cout << "Антисимметрично\n";
    }
    else
    {
        cout << "Не является симметричным, антисимметричным, асимметричным\n";
    }
}

void Transitivity(vector<vector<int>> table)
{
    cout << "Транзитивность: ";

    int number_of_elements = table.size();
    bool true_flag = true,
        def_flag = false;

    for (int y = 0; y < number_of_elements; y++)
    {
        for (int x = 0; x < number_of_elements; x++)
        {
            if ((table[y][x] == 1) and (x != y))
            {
                for (int z = 0; z < number_of_elements; z++)
                {
                    if ((def_flag == false) and (x != z) and (table[x][z] == 1) and (table[y][z] == 1))
                    {
                        def_flag = true;
                    }

                    if (table[x][z] == 1 and table[y][z] == 0)
                    {
                        true_flag = false;
                        goto breakTransitivityCycle;
                    }
                }
            }
        }
    }
breakTransitivityCycle:

    if (true_flag)
    {
        if (def_flag)
        {
            cout << "Транзитивно\n";
        }
        else
        {
            cout << "Невозможно определить в данном множестве\n";
        }
    }
    else
    {
        cout << "Нетранзитивно\n";
    }
}

void Completeness(vector<vector<int>> table)
{
    cout << "Полнота: ";

    int number_of_elements = table.size();
    bool true_flag = true;

    for (int y = 0; y < number_of_elements; y++)
    {
        for (int x = y + 1; x < number_of_elements; x++)
        {

            if (table[y][x] == 0 and table[x][y] == 0)
            {
                true_flag = false;
                goto breakCompletenessCycle;
            }
        }
    }
breakCompletenessCycle:

    if (true_flag)
    {
        cout << "Связно\n";
    }
    else
    {
        cout << "Несвязно\n";
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
	ifstream ftable("matrix.txt");
	if (!ftable)
	{
		cerr << "Ошибка открытия файла" << endl;
		return 1;
	}

    vector<vector<int>> table;
    string str;
    int ymax = 0, xmax = 0, x = 0;

    while (getline(ftable, str))
    {
        x = 0;
        vector<int> tmpv;
        for (char c : str)
        {          
            if (c == '0')
            {
                tmpv.push_back(0);
                x++;
            }
            else if (c == '1')
            {
                tmpv.push_back(1);
                x++;
            }
        }
        table.push_back(tmpv);
        ymax++;
        xmax = max(x, xmax);
    }

    ftable.close();

    if (ymax != xmax)
    {
        cerr << "Неверная таблица" << endl;
        return 2;
    }

    cout << "Считанная таблица:" << endl;
    for (const auto& row : table) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    ReflexivitySymmetry(table);
    Transitivity(table);
    Completeness(table);
}