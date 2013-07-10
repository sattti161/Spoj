#include <iostream>

using namespace std;

void Merge(long long int *arr, int low, int mid, int high);
void MergeSort(long long int *arr, int low, int high);
long int BinarySearch(long long int *arr, int key, int low, int high);


int main() {
	vector <long long int> answers;
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		long long int arr[n], original_arr[n];

		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			original_arr[j] = arr[j];
		}

		MergeSort(arr, 0, n-1);
		int temp = 0;
		for (int j = 0; j < n; j++) {
			temp += BinarySearch()
		}
	}

	for (int i = 0; i < answers.size(); i++) cout << answers[i] << endl;
}


long int BinarySearch(long long int *arr, int key, int low, int high) {
	if (low == high) {
		if (key < arr[low]) return low;
		else return low + 1;
	}

	int mid = low + (high - low) / 2;
	if (arr[mid] <= key && key < arr[mid + 1])
		return mid + 1;
	if (key < arr[mid])
		return BinarySearch(arr, key, low, mid);
	else
		return BinarySearch(arr, key, mid + 1, high);
}


long long int GetNumSwaps(long long int *original_arr, long long int *sorted_arr) {
	int num_swaps = 0;

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

