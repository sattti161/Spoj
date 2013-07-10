#include <iostream>
#include <stdio.h>
using namespace std;


int main() {
	long long int t; cin >> t;
	for (long long int i = 0; i < t; i ++) {
		long long int n, temp; scanf("%lld", &n);
		long long int sum = 0;
		for (long long int i = 0; i < n; i++) {
			scanf("%lld", &temp);
			sum += temp;
			sum = sum % n;
		}

		if (sum % n == 0) printf("YES\n");
		else printf("NO\n");
	}
}
