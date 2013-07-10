#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

long long int GetNumPosDecodings(vector <char> & str, long long int pos, map<long long int, long long int> & mymap);
vector <char> StandardiseString(string str);

int main(int argc, char *argv[]) {
	vector <long long int> answers;
	string str;

	while (true) {
		cin >> str;
		if (str == "0") break;
		map <long long int, long long int> mymap;
		vector <char> vec = StandardiseString(str);

		mymap[str.size() - 1] = 1;
		answers.push_back(GetNumPosDecodings(vec, 0, mymap));
	}

	for (long long int i = 0; i < answers.size(); i++)
		cout << answers[i] << endl;
}

vector <char> StandardiseString(string str) {
	vector <char> vec;
	long long int count = 0;
	vec.push_back(str[0]);
	for (long long int i = 1; i < str.size(); i++) {
		vec.push_back(str[i]);
		if (str[i] == '0') {
			vec[i] = 'z';
			vec[i - 1] = 'z';
		}
	}
	if (str[str.size() - 1] != '0') vec.push_back(str[str.size() - 1]);

	return vec;
}

long long int GetNumPosDecodings(vector <char> & str, long long int pos, map<long long int, long long int> & mymap) {
	if (mymap.find(pos) != mymap.end()) return mymap[pos];

	if (pos == str.size() - 1) {
		mymap[pos] = 1;
		return 1;
	}

	if(pos >= str.size()) return 0;

	if (pos + 1 < str.size() && (10 * (str[pos] - 48) + str[pos + 1] - 48) <= 26) {
		if (pos == str.size() - 2) mymap[pos] = 2;
		else mymap[pos] = GetNumPosDecodings(str, pos + 1, mymap) + GetNumPosDecodings(str, pos + 2, mymap);
	}

	else mymap[pos] = GetNumPosDecodings(str, pos + 1, mymap);

	return mymap[pos];
}
