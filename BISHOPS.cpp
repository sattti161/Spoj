#include <iosfwd>
#include <iostream>
#include <string>

using namespace std;

string AddStringsAsInt(string str1, string str2);
string SubtractStringsAsInt(string str1, string str2);

int main(int argc, char *argv[]) {
	string str;
	while (cin >> str) {
		if (str == "1") {
			cout << "1\n"; continue;
		}
		if (str == "0") {
			cout << "0\n"; continue;
		}
		string temp = SubtractStringsAsInt(str, "1");
		string answer = AddStringsAsInt(temp, temp);
		int i;
		for (i = 0; i < answer.size() - 1; i++) {
			if (answer[i] != '0') break;
		}

		for (i; i < answer.size(); i++) cout << answer[i];
		cout << endl;
	}
}

string SubtractStringsAsInt(string str1, string str2) {
	string result = str1;
	for (int i = 0; i < str1.size(); i++) result[i] = '0';

	int borrow = 0, diff = 0, i = str1.size() - 1, j = str2.size()  -1, k = 0;
	while (j >= 0) {
		if (str1[i] - str2[j] >= 0) borrow = 0;
		else borrow  = 1;
		diff = ((10 * borrow) + (str1[i] - 48)) - (str2[j] - 48);
		result[k] = diff + 48;
		i--; j--; k++;
		if ( i >= 0 && borrow > 0) str1[i] = str1[i] - 1;

	}

	while (i >= 0) {
		if (str1[i] - 48 >= 0) borrow = 0;
		else borrow = 1;
		result[k] = ((10 * borrow) + (str1[i] - 48)) + 48;
		k++; i--;
		if ( i >= 0 && borrow > 0) str1[i] = str1[i] - 1;
	}

	string fin_sum = result;
	for (int i = 0; i < result.size(); i++)
		fin_sum[i] = result[result.size() - 1 - i];
	return fin_sum;
}


string AddStringsAsInt(string str1, string str2) {
	string result; int large = 1;
	if (str1.size() >= str2.size()) result = str1 + '0';
	else result = str2 + '0';

	for (int i = 0; i < result.size(); i++) result[i] = '0';

	int i = str1.size() - 1, j = str2.size() - 1, carry = 0, sum = 0, k = 0;

	while ((i >= 0) && (j >= 0)) {
		sum = carry + str1[i] - 48 + str2[j] - 48;
		result[k] = (sum % 10) + 48;
		carry = sum / 10;
		i--; j--; k++;
	}

	if (i >= 0) {
		while (i >= 0) {
			sum = carry + str1[i] - 48;
			result[k] = (sum % 10) + 48;
			carry = sum / 10;
			i--; k++;
		}
	}

	else {
		while (j >= 0) {
			sum = carry + str2[j] - 48;
			result[k] = (sum % 10) + 48;
			carry = sum / 10;
			j--; k++;
		}
	}

	result[result.size() - 1] = carry + 48;

	string fin_sum = result;
	for (int i = 0; i < result.size(); i++)
		fin_sum[i] = result[result.size() - 1 - i];
	return fin_sum;
}
