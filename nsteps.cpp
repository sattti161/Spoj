#include <iostream>
#include <vector>

using namespace std;

int GetNumberAt(int x,  int y);

int main(int argc, char *argv[]) {
	int t, x, y;
	cin >> t;

	vector<int> answers;

	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		answers.push_back(GetNumberAt(x, y));
	}

	for (int  i = 0; i < t; i++) {
		if (answers[i] == -1)
			cout << "No Number\n";
		else
			cout << answers[i] << endl;
	}
}


int GetNumberAt(int x,  int y) {
	if (x < 0 || y < 0)
		return -1;
	if (x == y && x % 2 == 0)
		return 2 * x;
	if (x == y && x % 2 != 0)
		return 2 * x - 1;
	if (x == y + 2)
		return GetNumberAt(x - 2, y) + 2;
	return -1;
}

