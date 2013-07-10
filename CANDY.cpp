#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]) {
	while(true) {
		int n; scanf("%d", &n);
		if (n == -1) break;
		long long int sum = 0;
		int arr[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}

		if (sum % n != 0) {
			printf("-1\n");
			continue;
		}

		int desired = sum / n;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] < desired) sum += desired - arr[i];
		}
		printf("%lld\n", sum);
	}
}
