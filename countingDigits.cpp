#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector <int> getDigitCounts(int a, int b);
vector<int> NumtoDigit(int number);

int main(int argc, char *argv[]) {
	int a, b;
	vector<vector<int> >digit_counts;
	int i = 1000000000;
	cout << i << endl;
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
    
		vector<int> counts = getDigitCounts(a, b);
		digit_counts.push_back(counts);
	}

	for (int i = 0; i < digit_counts.size(); i++) {
		for (int j = 0; j < digit_counts[i].size(); j++)
			cout << digit_counts[i][j] << " ";
		cout << endl;
	}
}


vector <int> getDigitCounts(int a, int b) {
	int small, big;
	if (a <= b) {
		small = a;
		big = b;
	}
	else {
		small = b;
		big = a;
	}

	vector<int>digit_vector = NumtoDigit(big);

	int diff = big - small;
	int cyc_start_ends[9][2];
	for (int i = 0; i < 9; i++) {
		cyc_start_ends[i][0] = small % 10;
		cyc_start_ends[i][1] = big % 10;
		small = small / 10;
		big = big / 10;
	}
  
	cout << endl << "start end indices :\n ";
	for (int i = 0; i < 9; i++) {
		cout << cyc_start_ends[i][0] << " " << cyc_start_ends[i][1] << endl;
	}

	int num_cycles[9];
	num_cycles[8] = 0;
	//num_cycles[7] = 10 * num_cycles[8] + cyc_start_ends[7][1] - cyc_start_ends[6][1];
	for (int i = 7; i >= 0; i--) {
		if (cyc_start_ends[i + 1][1] >= cyc_start_ends[i + 1][0])
			num_cycles[i] = 10 * num_cycles[i + 1] + cyc_start_ends[i + 1][1] - cyc_start_ends[i + 1][0];
		else
			num_cycles[i] = 10 * num_cycles[i + 1] - 1 + 10 * cyc_start_ends[i + 1][1] - cyc_start_ends[i + 1][0];

	}

	cout << endl << "num cycles: ";
	for (int i = 0; i < 9; i++)
		cout << num_cycles[i] << " ";
	cout << endl;

	cout << "HERE: " << digit_vector.size() << endl;

	vector <int> digit_counts;
	for (int i = 0; i < 10; i++) {
		digit_counts.push_back(0);

		for (int j = 0; j < digit_vector.size(); j++) {
			digit_counts[i] += num_cycles[j];
		}
	}

	cout << "Digit counts: ";
	for (int i = 0; i < 10; i++)
		cout << digit_counts[i] << " " ;
	cout << endl;

	for (int i = 0; i < digit_vector.size(); i++) {
		if (cyc_start_ends[i][1] >= cyc_start_ends[i][0]) {
			for (int j = cyc_start_ends[i][0]; j <= cyc_start_ends[i][1]; j++) {
				digit_counts[j] += (int) pow(10, digit_vector.size() - 1 - i);
				for (int k = i - 1; k >= 0; k--) {
					digit_counts[][]
				}
			}
		}
		else {
			for (int j = cyc_start_ends[i][1] + 1; j < cyc_start_ends[i][0]; j++)
				digit_counts[j] -= (int) pow(10, digit_vector.size() - 1 - i);
		}
	}
	cout << "Digit counts: ";
		for (int i = 0; i < 10; i++)
			cout << digit_counts[i] << " " ;
		cout << endl;
	return digit_counts;
}


vector<int> NumtoDigit(int number){
    vector<int> digit_vector;

    while(number > 0){
	digit_vector.insert(digit_vector.end(), number % 10);
	number = number / 10;
    }
    return digit_vector;
}
