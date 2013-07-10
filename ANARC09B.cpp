#include <iostream>

using namespace std;
long long int FindGcd(long long int a, long long int b) ;


int main() {
	while (true) {
		long long int w, h, lcm; cin >> w >> h;
		if (w == 0 && h == 0) break;
		if (w >= h) lcm = (w * h) / FindGcd(w, h);
		else lcm = (w * h) / FindGcd(h, w);
		cout << (lcm / w) * (lcm / h) << endl;
	}
}

long long int FindGcd(long long int a, long long int b) {
	if (a % b == 0) return b;
	else return FindGcd(b, a % b);
}
