#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> Tokenize(string str, char delim);

int main(int argc, char *argv[]) {
	int t; cin >> t;
	string s;
	getline(cin, s);
	for (int i = 0; i < t; i++) {
		getline(cin, s);

		vector <string> words  = Tokenize(s, ' ');

		int count = 1, max = 1;
		for (int i = 1; i < words.size(); i++) {
			if (words[i].size() == words[i - 1].size()) count ++;
			else {
				if (max < count) max = count;
				count = 1;
			}
		}
		cout << max << endl;
	}
}


vector <string> Tokenize(string str, char delim) {
	vector <string> tokens;
	vector <char> word, null_word;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			tokens.push_back(string(word.begin(), word.end()));
			word = null_word;
			continue;
		}
		word.push_back(str[i]);
	}

	return tokens;
}
