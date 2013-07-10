#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c;

	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if (c - b == b - a)
			cout << "AP " << c + (c - b) << endl;
		else if (c / b == b / a)
			cout << "GP " << c * (c / b) << endl;
	}
}
