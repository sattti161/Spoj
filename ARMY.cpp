#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int g, m; cin >> g >> m;
		int arr1[g], arr2[m];
		for (int j = 0; j < g; j++) cin >> arr1[j];
		for (int j = 0; j < m; j++) cin >> arr2[j];
		int max1 = arr1[0], max2 = arr2[0];
		for (int j = 1; j < g; j++) if (arr1[j] > max1) max1 = arr1[j];
		for (int j = 1; j < m; j++) if  (arr2[j] > max2) max2 = arr2[j];

		if (max1 >= max2) cout << "Godzilla\n";
		else cout << "MechaGodzilla\n";
	}
}
