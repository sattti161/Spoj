#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	for (int  i = 0; i < t; i++) {
		long int temp; scanf("%ld", &temp);
		int skip = 0;
		for (int i = 1; (i * (i + 1)) / 2 <= temp; i++) skip = i;

		if ((skip * (skip + 1)) / 2 == temp) {
			if (skip % 2 == 0) cout << "TERM " << temp << " IS " << skip << "/1" << endl;
			else cout << "TERM " << temp << " IS " << "1/" << skip << endl;
			continue;
		}
		if ((skip + 1) % 2 != 0) cout << "TERM " << temp << " IS " << skip + 2 + ((skip * (skip + 1)) / 2) - temp << "/" << temp - ((skip * (skip + 1)) / 2) << endl;
		else cout << "TERM " << temp << " IS " << temp - ((skip * (skip + 1)) / 2) << "/" << skip + 2 + ((skip * (skip + 1)) / 2) - temp << endl;
	}
}
