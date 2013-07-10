#include <iostream>
#include <string>
#include <vector>
using namespace std;

int FindLcs(string str1, string str2, int i, int j, vector < vector<int> > & table);
int FindMax(int num1, int num2);

int count = 0;

int main (int argc, char *argv[]) {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		string str1, str2;
		vector < vector<int> > table;
		cin >> str1;
		str2 = str1;
		for (int k = 0; k < str1.size(); k++) str2[k] = str1[str1.size() - 1 - k];

		for (int j = 0; j < str1.size(); j++) {
			vector <int> temp;
			for (int k = 0; k < str2.size(); k++)
				temp.push_back(-1);
			table.push_back(temp);
		}

		cout << str1.size() - FindLcs(str1, str2, str1.size() - 1, str2.size() - 1, table) << endl;
		cout << "size, count: " << str1.size () <<  " " << count << endl;
	}
}


int FindLcs(string str1, string str2, int i, int j, vector <vector <int> > & table) {
	count++;
	if (i < 0 || j < 0 || i >= str1.size() || j >= str2.size()) return 0;

	if(table[i][j] != -1) return table[i][j];

	if (str1[i] == str2[j]) {
		table[i][j] = 1;
		if(i > 0 && j > 0 && table[i -1][j - 1] != -1) table[i][j] = table[i - 1][j - 1];
		else if (i > 0 && j > 0) table[i][j] += FindLcs(str1, str2, i - 1, j - 1, table);
		return table[i][j];
	}

	else {
		int max1 = 0, max2 = 0;
		if (i > 0 && table[i - 1][j] != -1) max1 = table[i - 1][j];
		else if (i > 0) max1 = FindLcs(str1, str2, i - 1, j, table);

		if (j > 0 && table[i][j - 1] != -1) max2 = table[i][j - 1];
		else if (j > 0) max2 = FindLcs(str1, str2, i, j - 1, table);

		table[i][j] = FindMax(max1, max2);
		return table[i][j];
	}
}

int FindMax(int num1, int num2) {
	if (num1 >= num2) return num1;
	else return num2;
}
