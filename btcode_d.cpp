#include <iostream>

using namespace std;

long long int GetBestProfit(int *waiters, int *customers, long long int *costs, int n);

int main (int argc, char *argv[]) {
	int t; cin >> t;
	long long int answers[t];
	for (int i = 0; i < t; i++) answers[i] = 0;

	for (int k = 0; k < t; k++) {
		int m, n; cin >> m >> n;
		int waiters[m][n], customers[m][n];
		long long int costs[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cin >> waiters[i][j];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cin >> customers[i][j];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				cin >> costs[i][j];
		}

		for (int i = 0; i < m; i++)
			answers[k] += GetBestProfit(waiters[i], customers[i], costs[i], n);
	}

	for (int i = 0; i < t; i++)
		cout << answers[i] << endl;
}


long long int GetBestProfit(int *waiters, int *customers, long long int *costs, int n) {
	long long int max = 0, temp = 0;
	for (int i = 0; i < n; i++) {
		if (waiters[i] >= customers[i])
			temp = customers[i];
		else temp = waiters[i];

		if (temp * costs[i] > max)
			max = temp * costs[i];
	}

	return max;
}
