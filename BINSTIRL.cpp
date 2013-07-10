#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

long long int GetStirlingNum(long long int m, long long int n, vector <vector <long long int> > & tab);

int main(int argc, char *argv[]) {
	int t; cin >> t;

	for (int i = 0; i < t; i++) {
		long long int m, n; scanf("%lld %lld", &n, &m); //cin >> n >> m;
		vector <vector <long long int> > tab;
		for (long long int j = 0; j <= n; j++) {
			vector <long long int > temp;
			for (long long int k = 0; k <= m; k++) temp.push_back(-1);
			tab.push_back(temp);
		}
		printf("%d\n", (int)(GetStirlingNum(m, n, tab) % 2));
	}
}


long long int GetStirlingNum(long long int m, long long int n, vector <vector <long long int> > & tab) {
	if (tab[n][m] != -1) return tab[n][m];
	if (m == 0 && n == 0) {
		tab[0][0] = 1;
		return 1;
	}
	if (n == 0 && m != 0) {
		tab[n][m] = 0;
		return 0;
	}
	if (m == 0 && n != 0) {
		tab[n][m] = 0;
		return 0;
	}

	tab[n][m] = m * GetStirlingNum(m, n - 1, tab) + GetStirlingNum(m - 1, n - 1, tab);
	return tab[n][m];
}


