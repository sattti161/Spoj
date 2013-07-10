#include <iostream>
#include <vector>

using namespace std;

vector<int> NumtoDigit(int number);
int DigitstoNumber(vector<int>digits);

int main(int argc, char *argv[]) {
	int t, m, n;
	cin >> t;
	vector<int> sums;

	for (int i = 0; i < t; i++) {
		cin >> m >> n;
		vector<int> digits1 = NumtoDigit(m);
		vector<int> digits2 = NumtoDigit(n);
		int m1 = DigitstoNumber(digits1);
		int n1 = DigitstoNumber(digits2);
		sums.push_back(DigitstoNumber(NumtoDigit(m1 + n1)));
	}

	for (int i = 0; i < sums.size(); i++)
		cout << sums[i] << endl;
}


int DigitstoNumber(vector<int>digits) {
	int num = 0;
	for (int i = 0; i < digits.size(); i++)
		num = 10 * num + digits[i];
	return num;
}


vector<int> NumtoDigit(int number){
	vector<int> digit_vector;

    while(number > 0) {
    	digit_vector.insert(digit_vector.end(), number % 10);
    	number = number / 10;
    }
    return digit_vector;
}
