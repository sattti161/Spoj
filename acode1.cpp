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
		//cout << str;
		if (str == "0") break;
		map <long long int, long long int> mymap;
		vector <char> vec = StandardiseString(str);

		for (int i = 0; i < vec.size(); i++) cout << vec[i];
		cout << endl;
		/*while (str.size() >= 2 && str[1] == '0') {
			if (str.size() > 2) str = str.substr(2, str.size() - 2);
			else str = "";
		} */
		//cout << str << endl;
		/**if (str.size() >= 2 && (10 * (str[0] - 48) + str[1] -48) <= 26)
			answers.push_back(GetNumPosDecodings(vec, 0, mymap) + GetNumPosDecodings(vec, 1, mymap));
		else answers.push_back(GetNumPosDecodings(vec, 1, mymap)); **/
		mymap[str.size() - 1] = 1;
		answers.push_back(GetNumPosDecodings(vec, 0, mymap));
		//cout << "Size of the given string: " << str.size() << endl;
		//for (int i = 1; i <= str.size(); i++) cout << str.substr(str.size() - i) << "   "<< mymap[str.size() - i] << endl;
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
	//cout << "After Removing 0's the size is: " << vec.size() << endl;
	return vec;
}

long long int GetNumPosDecodings(vector <char> & str, long long int pos, map<long long int, long long int> & mymap) {
	//cout << "IN get fun pos: " << pos << endl;
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

/**
long long int GetNumPosDecodings(string & str, long long int pos, map<long long int, long long int> & mymap) {
	//cout << "IN get fun pos: " << pos << endl;
	if (mymap.find(pos) != mymap.end()) return mymap[pos];

	if (pos == str.size() - 1) {
		mymap[pos] = 1;
		return 1;
	}

	if(pos >= str.size()) return 0;

	if (str[pos] == '0' || str[pos + 1] == '0' ) {
		mymap[pos] = GetNumPosDecodings(str, pos + 1, mymap);
		return mymap[pos];
	}

	if (pos + 2 < str.size() && str[pos + 2] == '0') {
		mymap[pos] = mymap[pos + 1] = mymap[pos + 2] = GetNumPosDecodings(str, pos + 2, mymap);
		return mymap[pos];
	}


	if (pos + 1 < str.size() && str[pos + 1] != 0 && (10 * (str[pos] - 48) + str[pos + 1] - 48) <= 26) {
		if (pos == str.size() - 2) mymap[pos] = 2;
		else mymap[pos] = GetNumPosDecodings(str, pos + 1, mymap) + GetNumPosDecodings(str, pos + 2, mymap);
	}

	else mymap[pos] = GetNumPosDecodings(str, pos + 1, mymap);

	return mymap[pos];
} **/

/**
long long int GetNumPosDecodings(vector <char> & str, long long int pos, map<long long int, long long int> & mymap) {
	if (pos == str.size() - 1) {
		mymap[pos] = 1;
		return 1;
	}

	if(pos >= str.size()) return 1;

	map <long long int, long long int>::iterator it = mymap.find(pos);
	if (it != mymap.end()) return mymap[pos];


	if (str[pos] == '0') {
		mymap[pos] = GetNumPosDecodings(str, pos + 1, mymap);
		return mymap[pos];
	}


	if (pos + 1 < str.size() && str[pos + 1] != 0 && (10 * (str[pos] - 48) + str[pos + 1] -48) <= 26)
		mymap[pos] = GetNumPosDecodings(str, pos + 1, mymap) + GetNumPosDecodings(str, pos + 2, mymap);

	else mymap[pos] = GetNumPosDecodings(str, pos + 1, mymap);

	return mymap[pos];
} **/

