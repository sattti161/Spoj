#include <iostream>
#include <vector>

using namespace std;

void Merge(long long int *arr, int low, int mid, int high);
void MergeSort(long long int *arr, int low, int high);
void Adjust(long long int *arr, int n, int x);
bool BinarySearch(long long int *arr, int key, int low, int high);
vector<long long int> GetMaxValues(long long int *arr, int x, int y);

int main(int argc, char *argv[]) {
	int n, q;
	cin >> n;

	long long int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> q;

	int x, y;
	vector <int> max_sums;
	char query;

	for (int i = 0; i < q; i++) {
		cin >> query >> x >> y;

		if (query == 'U')
			arr[x - 1] = y;

		if (query == 'Q') {
			vector<long long int> max_values = GetMaxValues(arr, x - 1, y - 1);
			max_sums.push_back(max_values[0] + max_values[1]);
		}
	}

	for (int i = 0; i < max_sums.size(); i++)
		cout << max_sums[i] << endl;
}


vector<long long int> GetMaxValues(long long int *arr, int x, int y) {
	int max1 = - 1, max2 = -1, index = 0;
	for (int i = x; i <= y; i++) {
		if (max1 < arr[i]) {
			max1 = arr[i];
			index = i;
		}
	}

	for (int i = x; i <= y; i++) {
		if (max2 < arr[i] && i != index) {
			max2 = arr[i];
		}
	}
	vector<long long int> max_values;
	max_values.push_back(max1);
	max_values.push_back(max2);
	return max_values;
}

bool BinarySearch(long long int *arr, int key, int low, int high) {
	if (low > high)
		return false;

	int mid = low + (high - low) / 2;
	if (arr[mid] == key)
		return true;
	if (key < arr[mid])
		return BinarySearch(arr, key, low, mid - 1);
	else
		return BinarySearch(arr, key, mid + 1, high);
}


void Adjust(long long int *arr, int n, int x) {
	int temp = arr[x];
	bool flag = false;
	for (int i = x; i < n - 1; i++)
		arr[i] = arr[i + 1];

	for (int i = 0; i < n - 1 && !flag; i++) {
		if (arr[i] > temp) {
			for (int j = n - 1; j > i; j--)
				arr[j] = arr[j - 1];
			arr[i] = temp;
			flag = true;
		}
	}

	if (!flag) arr[n - 1] = temp;
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

