#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetDigitSum(string str, int start_pos, int end_pos);
int GetNumGroups(string str, int pos, vector <int> & cum_sum, int prev_sum);
vector <int> GetCumulativeSum(string str);


int main(int argc, char *argv[]) {
	vector <int> answers;
	while (true) {
		string str; cin >> str;
		if (str == "bye") break;
		vector <int> cum_sum = GetCumulativeSum(str);
		answers.push_back(GetNumGroups(str, 0, cum_sum, 0));
	}

	for (int i = 0; i < answers.size(); i++) cout << i+1 << ". " << 1 + answers[i] << endl;
}


int GetNumGroups(string str, int pos, vector <int> & cum_sum, int prev_sum) {
	int count = 0;
	for (int i = pos; i < str.size() - 1; i++) {
		int sum1 = cum_sum[i] - cum_sum[pos] + str[pos] - 48;
		int sum2 = cum_sum[cum_sum.size() - 1] - cum_sum[i];
		if (sum1 > sum2) break;

		if (prev_sum <= sum1)
			count += 1 + GetNumGroups(str, i + 1, cum_sum, sum1);
		else continue;
	}

	return count;
}


vector <int> GetCumulativeSum(string str) {
	vector <int> cum_sum;
	int temp = 0;
	for (int i = 0; i < str.size(); i++) {
		temp += str[i] - 48;
		cum_sum.push_back(temp);
	}
	return cum_sum;
}


int GetDigitSum(string str, int start_pos, int end_pos) {
	int digit_sum = 0;
	for (int i = start_pos; i <= end_pos; i++) digit_sum += str[i] - 48;
	return digit_sum;
}
