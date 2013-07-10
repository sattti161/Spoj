#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
	int n, count = 0; cin >> n;
	map <long int, bool> mymap, cd_map;
	long int max, temp;
	for (int i = 0; i < n - 1; i++){
		cin >> temp;
		mymap[temp] = false;
	}
	cin >> temp;
	mymap[temp] = false;
	max = temp;

	for (int i = 1; i <= max; i++) {
		bool flag = false, consider = false;
		for (int j = 0; 1 + i * j <= max; j++) {
			if (mymap.find(1 + i * j) != mymap.end()){
				if (mymap[1 + i * j] == false) consider = true;
			}
			else {
				flag = true;
				break;
			}
		}

		if (!flag && consider) {
			for (int j = 0; 1 + i * j <= max; j++) mymap[1 + i * j] = true;
			count ++;
		}
	}

	cout << count << endl;

}
