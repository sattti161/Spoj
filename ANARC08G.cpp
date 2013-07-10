#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int k = 0;

	while (true) {
		k++;
		int n; scanf("%d", &n);
		if (n == 0) break;
		int adj[n][n];
		long long int sum = 0, min_sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j= 0; j < n; j++){
				scanf("%d", &adj[i][j]);
				sum += adj[i][j];
			}
		}


		for (int i = 0; i < n; i++) {
			long long int temp_sum = 0;
			for (int j = 0; j < n; j++) temp_sum += adj[j][i] - adj[i][j];
			if (temp_sum > 0) min_sum += temp_sum;
		}
//		answers1.push_back(sum); answers2.push_back(min_sum);
		printf("%d. %lld %lld\n",  k, sum, min_sum);
		//cout << k << ". " << sum << " " << min_sum << endl;
	}

	//sfor (int i = 0; i < answers1)
}
