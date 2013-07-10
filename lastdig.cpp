#include <iostream>
#include <vector>

using namespace std;

int GetLastDig(int, long long int);

int main () {
	int t; cin >> t;
	vector <int> a;
	long long int ix; int bs;

	for (int i = 0; i < t; i++) {
		cin >> bs >> ix;
		a.push_back(GetLastDig(bs, ix));
	}
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
}

int GetLastDig(int bs, long long int ix) {
	if (ix == 0) return 1;
	vector <int> c;
	int n = bs % 10;
	c.push_back(n);

	while (true) {
		n = (n * bs) % 10;
		if (c[0] == n) break;
		c.push_back(n);
	}

	if (ix % c.size() == 0) return c[c.size() - 1];
	return c[(ix % c.size()) - 1];
}
