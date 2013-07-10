#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long int GetNum(vector <char> str, long long int start, long long int end);
vector <char> RemoveSpaces(string str);


int main(int argc, char *argv[]) {
	long long int t; cin >> t;
	string input_str; getline(cin, input_str);
	for (int i = 0; i < t; i++) {
		getline(cin, input_str);
		string input_str; getline(cin, input_str);
		vector <char> str = RemoveSpaces(input_str);
		long long int start = 0, end = 0, j = 0;
		char oper;

		while (!(str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/') ) j++;
		long long int num = GetNum(str, start, j - 1);

		while(true) {
			if (j >= str.size()) break;
			oper = str[j]; j++;
			start = j;
			while (j < str.size() && !(str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/') ) j++;

			if (oper == '+') num += GetNum(str, start, j - 1);
			if (oper == '-') num -= GetNum(str, start, j - 1);
			if (oper == '*') num *= GetNum(str, start, j - 1);
			if (oper == '/') num /= GetNum(str, start, j - 1);
		}

		cout << num << endl;
	}

}


vector <char> RemoveSpaces(string str) {
	vector <char> result;
	for (int i = 0; i < str.size(); i++) {
		if (!(str[i] == ' ' || str[i] == '=')) result.push_back(str[i]);
	}
	return result;
}

long long int GetNum(vector <char> str, long long int start, long long int end) {
	long long int num = 0;
	for (long long int i = start; i <= end; i++) num = num * 10 + (str[i] - 48);
	return num;
}
