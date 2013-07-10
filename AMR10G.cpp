#include <iostream>

using namespace std;

void Merge(long long int *arr, int low, int mid, int high);
void MergeSort(long long int *arr, int low, int high);
long long int GetMinDiff(long long int *arr, int n, int k);

int main(int argc, char *argv[]) {
	int t; cin >> t;
	//long long int answers[t];
	for (int i = 0; i < t; i++) {
		int n, k; cin >> n >> k;
		long long int arr[n];
		for (int j = 0; j < n; j++) cin >> arr[j];

		MergeSort(arr, 0, n - 1);
		cout << GetMinDiff(arr, n, k) << endl;
	}

	//for (int i = 0; i < t; i++) cout << answers[i] << endl;
}


long long int GetMinDiff(long long int *arr, int n, int k) {
	long long int min = arr[k - 1] - arr[0];
	for (int i = 1; i <= n - k; i++) {
		if (arr[k - 1 + i] - arr[i] < min) min = arr[k - 1 + i] - arr[i];
	}
	return min;
}

void MergeSort(long long int *arr, int low, int high) {
	if (low ==  high)
		return;
	if (high > low && high > 0  && low >= 0) {
		int mid = low + (high - low) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}



void Merge(long long int *arr, int low, int mid, int high) {
	long long int left[mid - low + 1], right[high - mid];

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
