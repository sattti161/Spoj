#include <iostream>
#include <string>

using namespace std;

void Merge(string *arr, int low, int mid, int high);
void MergeSort(string *arr, int low, int high);


int main(int argc, char *argv[]) {
	int t; cin >> t;
	int answers[t];

	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		string numbers[n];

		for (int j = 0; j < n; j++)
			cin >> numbers[j];

		MergeSort(numbers, 0, n - 1);
	}
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
