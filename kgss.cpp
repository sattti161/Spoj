#include <iostream>
#include <vector>

using namespace std;

vector<long long int> GetMaxValues(long long int *arr, int x, int y);

int main(int argc, char *argv[]) {
	int n, q;
	cin >> n;

	long long int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> q;

	int x, y;
	vector <int> max_sums;
	char query;

	for (int i = 0; i < q; i++) {
		cin >> query >> x >> y;

		if (query == 'U')
			arr[x - 1] = y;

		if (query == 'Q') {
			vector<long long int> max_values = GetMaxValues(arr, x - 1, y - 1);
			max_sums.push_back(max_values[0] + max_values[1]);
		}
	}

	for (int i = 0; i < max_sums.size(); i++)
		cout << max_sums[i] << endl;
}


vector<long long int> GetMaxValues(long long int *arr, int x, int y) {
	int max1 = - 1, max2 = -1, index = 0;
	for (int i = x; i <= y; i++) {
		if (max1 < arr[i]) {
			max1 = arr[i];
			index = i;
		}
	}

	for (int i = x; i <= y; i++) {
		if (max2 < arr[i] && i != index) {
			max2 = arr[i];
		}
	}
	vector<long long int> max_values;
	max_values.push_back(max1);
	max_values.push_back(max2);
	return max_values;
}
