#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		vector <int, int> coordinates;
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			coordinates.push_back(make_pair(x, y));
		}

		pair <int , int> temp = coordinates[0];

		while (true) {

		}

	}
}
