#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GetInputVector() {
	string input;
	cout << "Введите вектор: " << endl;
	getline(cin, input);

	for (char c : input) {
		if (c != '0' && c != '1') {
			cout << "Ошибка: Лишний символ в строке. Только 0 и 1 без пробелов." << endl;
			return GetInputVector();
		}
	}

	int size = 1;
	while (size < input.size()) {
		size *= 2;
	}

	if (input.size() != size) {
		cout << "Ошибка: Неверная длина вектора. Длина должна быть степенью двойки." << endl;
		return GetInputVector();
	}

	vector<int> vectorResult;
	for (char c : input) {
		vectorResult.push_back(c - '0');
	}

	return vectorResult;
}

int GetVariables(vector<int> line){
	int variables = 0,
		size = line.size();
	while (size != 1) {
		size /= 2;
		variables++;
	}
	return variables;
}

vector<vector<int>> TruthTable(vector<int> line) {
	vector<vector<int>> truth_table;
	int variables = GetVariables(line);

	cout << "Таблица истинности:\n";
	for (int x = variables - 1; x >= 0; x--) {
		vector<int> row;
		for (int y = 0; y < line.size(); y++) {
			row.push_back((y / (1 << x)) % 2);
		}
		truth_table.push_back(row);
	}

	for (int x = variables - 1; x >= 0; x--) {
		cout << 'x' << x << ' ';
	}
	cout << 'f' << endl;

	for (int y = 0; y < line.size(); y++) {
		for (int x = 0; x < variables; x++) {
			cout << truth_table[x][y] << ' ';
			int spaces = x / 10;
			for (int i = 0; i < spaces; i++)
			{
				cout << ' ';
			}
			cout << ' ';
		}
		cout << line[y] << endl;
	}
	
	return truth_table;
}

vector<vector<int>> NormalForms(vector<int> line, vector<vector<int>> truth_table)
{
	vector<vector<int>> disjunction, conjunction;
	int variables = GetVariables(line);

	for (int y = 0; y < line.size(); y++) {
		vector<int> tmp;
		for (int x = 0; x < variables; x++) {
			tmp.push_back(truth_table[x][y]);
		}
		if (line[y] == 1) {
			disjunction.push_back(tmp);
		}
		else {
			conjunction.push_back(tmp);
		}
	}

	cout << "СДНФ: ";
	if (disjunction.empty()) {
		cout << 0;
	}
	else {
		for (int y = 0; y < disjunction.size(); y++) {
			if (y > 0) cout << " ";
			for (int x = 0; x < variables; x++) {
				if (disjunction[y][x] == 0) cout << '~';
				cout << 'x' << variables - 1 - x;
			}
		}
	}

	cout << "\nСКНФ: ";
	if (conjunction.empty()) {
		cout << 1;
	}
	else {
		for (int y = 0; y < conjunction.size(); y++) {
			cout << '(';
			for (int x = 0; x < variables; x++) {
				if (x > 0) cout << " ";
				if (conjunction[y][x] == 1) cout << '~';
				cout << 'x' << variables - 1 - x;
			}
			cout << ')';
		}
	}
	cout << endl;

	return disjunction;
}

vector<vector<int>> Gluing(vector<vector<int>> disjunction, int variables) {
	int current_implicats_end = disjunction.size();
	int current_implicats_begin = 0;

	cout << "\nСклеивание:\n";

	for (int v = variables - 1; v > 0; v--) {
		cout << v << ":\n";
		int next_implicats = 0;

		for (int y = current_implicats_begin; y < current_implicats_end - 1; y++) {
			for (int y1 = y + 1; y1 < current_implicats_end; y1++) {
				vector<int> tmp(variables, 0);
				for (int x = 0; x < variables; x++) {
					tmp[x] = disjunction[y][x];
				}

				bool flag0 = true,
					flag1 = true;
				for (int x = 0; x < variables; x++) {
					if (tmp[x] != disjunction[y1][x] and flag0) {
						flag0 = false;
						tmp[x] = 9;
					}else if (tmp[x] != disjunction[y1][x] and !flag0){
						flag1 = false;
						break;
					}
				}

				if (flag1 and !flag0) {
					disjunction.push_back(tmp);
					next_implicats++;
					cout << y << '-' << y1 << " (" << current_implicats_end - 1 + next_implicats << ") ";
					for (int x = 0; x < variables; x++) {
						if (tmp[x] == 1) {
							cout << 'x' << variables - 1 - x;
						}
						else if (tmp[x] == 0) {
							cout << '~' << 'x' << variables - 1 - x;
						}
					}
					cout << endl;
				}
			}
		}

		if (next_implicats == 0)
		{
			cout << '-' << endl;
		}

		current_implicats_begin = current_implicats_end;
		current_implicats_end += next_implicats;
	}

	cout << "\nОставшиеся импликаты:\n";
	vector<vector<int>> implicats = disjunction;
	int y = disjunction.size() - 1;
	while(y > 0) {
		for (int y1 = y - 1; y1 >= 0; y1--) {
			bool flag = true;
			for (int x = 0; x < variables; x++) {
				if (disjunction[y][x] != implicats[y1][x] and disjunction[y][x] != 9) {
					flag = false;
					break;
				}
			}
			if (flag) {
				implicats.erase(implicats.begin() + y1);
			}
		}
		if (disjunction.size() > implicats.size()) {
			disjunction = implicats;
			y = disjunction.size();
		}
		y--;
	}

	for (int y = 0; y < implicats.size(); y++) {
		for (int x = 0; x < variables; x++) {
			if (implicats[y][x] == 1) {
				cout << 'x' << variables - 1 - x;
			}
			else if (implicats[y][x] == 0) {
				cout << '~' << 'x' << variables - 1 - x;
			}
		}
		cout << endl;
	}

	return implicats;
}

vector<vector<bool>> ImplicationMatrix(vector<vector<int>> disjunction, vector<vector<int>> implicats, int variables) {
	cout << "\nИмплицационная матрица:\n";
	vector<vector<bool>> implication_matrix;
	for (int y = 0; y < implicats.size(); y++) {
		vector<bool> tmp;
		for (int x = 0; x < disjunction.size(); x++) {
			tmp.push_back(true);
			for (int i = 0; i < variables; i++) {
				if (implicats[y][i] != disjunction[x][i] and implicats[y][i] != 9) {
					tmp[x] = false;
					break;
				}
			}
		}
		implication_matrix.push_back(tmp);
	}

	string max_space = "";
	for (int y = 0; y < implicats.size(); y++) {
		string tmp = "";
		for (int x = 0; x < variables; x++) {
			if (implicats[y][x] == 0) {
				tmp += '~';
			}
			if (implicats[y][x] != 9) {
				tmp += 'x' + to_string(x);
			}
		}
		while (max_space.size() < tmp.size()) {
			max_space += ' ';
		}
	}
	max_space += ' ';
	cout << max_space;

	vector<string> spaces;
	for (int y = 0; y < disjunction.size(); y++) {
		string tmp = "";
		for (int x = 0; x < variables; x++) {
			if (disjunction[y][x] == 0) {
				tmp += '~';
			}
			if (disjunction[y][x] != 9) {
				tmp += 'x' + to_string(variables - 1 - x);
			}
		}
		cout << tmp;
		for (int i = 0; i < tmp.size(); i++) {
			tmp[i] = ' ';
		}
		spaces.push_back(tmp);
		cout << ' ';
	}
	cout << endl;

	for (int y = 0; y < implicats.size(); y++) {
		string tmp = "";
		for (int x = 0; x < variables; x++) {
			if (implicats[y][x] == 0) {
				tmp += '~';
			}
			if (implicats[y][x] != 9) {
				tmp += 'x' + to_string(variables - 1 - x);
			}
		}
		cout << tmp;
		for (int i = tmp.size(); i < max_space.size(); i++) {
			cout << ' ';
		}

		for (int x = 0; x < disjunction.size(); x++) {
			if (implication_matrix[y][x]) {
				cout << '+';
			} 
			else {
				cout << ' ';
			}
			cout << spaces[x];
		}
		cout << endl;
	}

	return implication_matrix;
}

void MinimalForms(vector<vector<int>> implicats, int variables, vector<vector<bool>> implication_matrix) {
	cout << "\nМНДФ:\n";
	vector<vector<vector<int>>> minimal_forms;
	vector<bool> untouched_implicats(implicats.size(), true);
	for (int ui = 0; ui < implicats.size(); ui++) {
		vector<vector<int>> tmp;
		if (untouched_implicats[ui]) {
			untouched_implicats[ui] = false;
			tmp.push_back(implicats[ui]);
			vector<bool> untouched_disjunction(implication_matrix[0].size(), true);
			for (int x = 0; x < implication_matrix[0].size(); x++) {
				if (implication_matrix[ui][x]) {
					untouched_disjunction[x] = false;
				}
			}

			for (int ud = 0; ud < implication_matrix[0].size(); ud++) {
				if (untouched_disjunction[ud]) {
					int max_id;
					int max_points;
					bool is_max = true;
					for (int y = 0; y < implicats.size(); y++) {
						if (implication_matrix[y][ud]) {
							int points = 0;
							for (int x = 0; x < implication_matrix[0].size(); x++) {
								if (implication_matrix[y][x] and untouched_disjunction[x]) {
									points++;
								}
								else if (implication_matrix[y][x] and !untouched_disjunction[x]) {
									points--;
								}
							}
							if (is_max or max_points < points) {
								max_points = points;
								max_id = y;
							}
						}
					}

					for (int x = 0; x < implication_matrix[0].size(); x++) {
						if (implication_matrix[max_id][x]) {
							untouched_disjunction[x] = false;
						}
					}
					untouched_implicats[max_id] = false;
					tmp.push_back(implicats[max_id]);
				}
			}
			minimal_forms.push_back(tmp);
		}
	}

	bool is_min = true;
	int min;
	for (int z = 0; z < minimal_forms.size(); z++) {
		if (is_min or min > minimal_forms[z].size()) {
			min = minimal_forms[z].size();
		}
	}

	int size = minimal_forms.size() - 1;
	while (size > 0) {
		if (minimal_forms[size].size() > min) {
			minimal_forms.erase(minimal_forms.begin() + size);
		}
		size--;
	}

	for (int z = 0; z < minimal_forms.size(); z++) {
		for (int y = 0; y < minimal_forms[z].size(); y++) {
			for (int x = 0; x < variables; x++) {
				if (minimal_forms[z][y][x] == 0) {
					cout << '~';
				}
				if (minimal_forms[z][y][x] != 9) {
					cout << 'x' << variables - 1 - x;
				}
			}
			cout << ' ';
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	while(true) {
		vector<int> line = GetInputVector();
		int variables = GetVariables(line);
		vector<vector<int>> truth_table = TruthTable(line);
		vector<vector<int>> disjunction = NormalForms(line, truth_table);/*
		for (int y = 0; y < disjunction.size(); y++) {
			for (int x = 0; x < variables; x++) {
				cout << disjunction[y][x];
			}
			cout << endl;
		}*/
		vector<vector<int>> implicats = Gluing(disjunction, variables);/*
		for (int y = 0; y < implicats.size(); y++) {
			for (int x = 0; x < variables; x++) {
				cout << implicats[y][x];
			}
			cout << endl;
		}*/
		vector<vector<bool>> implication_matrix = ImplicationMatrix(disjunction, implicats, variables);
		MinimalForms(implicats, variables, implication_matrix);
		cout << "\n\n";
	}
	return 0;
}