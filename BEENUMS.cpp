#include <iostream>

using namespace std;

int main(int argc, char *arg[]) {
	while (true) {
		long long int num, prev = 1; cin >> num;
		bool flag = false;
		if (num == -1) break;
		for (int i = 1; ; i++) {
			if (prev > num) break;
			if (prev == num){
				flag = true;
				cout << "Y\n";
			}
			prev += 6 * i;
		}

		if (!flag) cout << "N\n";
	}
}
