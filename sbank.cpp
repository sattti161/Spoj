#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

void Merge(string *arr, int low, int mid, int high);
void MergeSort(string *arr, int low, int high);
vector<pair<string, int> > GetCounts(string *arr, int n);


int main(int argc, char *argv[]) {
	int t; cin >> t;
	vector<vector <pair<string, int> > > account_nos;

	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		string* arr = new string[n];
		getline(cin, arr[0]);
		for (int j = 0; j < n; j++)
			getline(cin, arr[j]);
		MergeSort(arr, 0, n - 1);
		account_nos.push_back(GetCounts(arr, n));
		string temp;
		if (i != t - 1)
			getline(cin, temp);
	}

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < account_nos[i].size();  j++)
			cout << account_nos[i][j].first << " " << account_nos[i][j].second << endl;
		cout << endl;
	}
}


vector<pair<string, int> > GetCounts(string *arr, int n) {
	vector<pair<string, int> > acc_nos;
	int i = 0;
	while (i < n) {
		pair<string, int> temp_pair = make_pair(arr[i], 1);
		i++;
		while (i < n && arr[i] == temp_pair.first) {
			temp_pair.second++;
			i++;
		}
		acc_nos.push_back(temp_pair);
	}
	return acc_nos;
}


void MergeSort(string *arr, int low, int high) {
	if (low ==  high)
		return;
	if (high > low && high > 0  && low >= 0) {
		int mid = low + (high - low) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}

void Merge(string *arr, int low, int mid, int high) {
	string left[mid - low + 1], right[high - mid];

	for (int i = 0; i < mid - low + 1; i++)
		left[i] = arr[low + i];
	for (int i = 0; i < high - mid; i++)
		right[i] = arr[mid + i + 1];

	int i = 0, j = 0, k = low;

	while (true) {
		if (i <= mid - low && j <= high - mid - 1 && left[i] <= right[j]){
			arr[k] = left[i];
			k++; i++;
		}
		if (i <= mid - low && j <= high - mid - 1 && left[i] > right[j]){
			arr[k] = right[j];
			j++; k++;
		}
		if (i > mid - low || j > high - mid - 1) break;
	}

	if (i > mid - low) {
		for (j; j <= high - mid - 1; j++) {
			arr[k] = right[j];
			k++;
		}
	}

	if (j > high - mid - 1) {
		for (i; i <= mid - low; i++) {
			arr[k] = left[i];
			k++;
		}
	}
}
