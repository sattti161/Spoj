#include <iostream>

using namespace std;
void Merge(int *arr, int low, int mid, int high);
void MergeSort(int *arr, int low, int high);

int main(int argc, char *argv[]) {
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		int arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		MergeSort(arr, 0, n-1);

		int count = 0; bool flag = false;
		for (int i = n - 1; i >= 0; i--) {
			count ++;
			if (count > arr[i]) {
				flag = true;
				cout << count - 1 << endl;
				break;
			}
		}

		if (!flag) cout << count << endl;
	}
}


void MergeSort(int *arr, int low, int high) {
	if (low ==  high)
		return;
	if (high > low && high > 0  && low >= 0) {
		int mid = low + (high - low) / 2;
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, mid, high);
	}
}


void Merge(int *arr, int low, int mid, int high) {
	int left[mid - low + 1], right[high - mid];

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
