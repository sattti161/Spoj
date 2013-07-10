#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
	long long int m, n, temp; cin >> m >> n;
	map <long long int, long long int> mymap;
	for (long long int i = 0; i < n; i++) {
		scanf("%lld", &temp);
		if (mymap.find(temp) == mymap.end()) mymap[temp] = 1;
		else mymap[temp] ++;
	}

	map <long long int, long long int>::iterator it;
	//for (it = mymap.begin(); it != mymap.end(); it++) cout << it->first << " " << it->second << endl;

	long long int i = 1;
	while (m > 0) {
		it = mymap.end(); it--;
		//for (int j = 0; j < i; j++) it--;
		//cout << "Here: " << it->first << " " << it->second << " and m is: " << m <<endl;
		if (m >= it->second) {
			m -= it->second;
			if (mymap.find(it->first - 1) == mymap.end()) mymap[it->first - 1] = it->second;
			else mymap[it->first - 1] += it->second;
			//mymap[it->first] = 0;
			mymap.erase(it->first);
		}
		else {
			if (mymap.find(it->first - 1) == mymap.end()) mymap[it->first - 1] = m;
			else mymap[it->first - 1] += m;
			mymap[it->first] -= m;
			//for (it = mymap.begin(); it != mymap.end(); it++) cout << it->first << " " << it->second << endl;
			break;
		}
		i++;
		//for (it = mymap.begin(); it != mymap.end(); it++) cout << it->first << " " << it->second << endl;
	}

	long long int sum = 0;
	//cout << endl;
	for (map <long long int, long long int>::iterator it = mymap.begin(); it != mymap.end(); it ++) {
		//cout << it->first << " " << it->second << endl;
		if (it->second <= 0) break;
		if (it->first > 0) sum += it->second * it->first * it->first;
	}
	cout << sum << endl;
}
