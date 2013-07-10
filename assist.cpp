#include <iostream>
#include <vector>
#include <math.h>
#include <map>

using namespace std;


void Merge(int *arr, int low, int mid, int high);
void MergeSort(int *arr, int low, int high);

int main(int argc, char *argv[]) {
	vector<int> numbers;
	int size = 0;
	while (true) {
		int temp; cin >> temp;
		if (temp == 0)
			break;
		numbers.push_back(temp);
		size ++;
	}
	int arr[size];
	for (int i  = 0; i < size; i++)
		arr[i] = numbers[i];
	MergeSort(arr, 0, size - 1);

	int answers[size];
	for (int i = 0; i < size; i++) {

	}

}

int GetNextPrime(vector<int>primes) {
	for (int j = primes[primes.size() - 1] + 1; true; j++) {
		bool flag = false;
		for (int i = 0; i < primes.size() && !flag && primes[]; i++) {

		}
	}
}


vector<int> GetPrimesTill(int num) {
	vector<int> primes;
	if (num >= 2) prime[2] = true;

	for (int i = 3; i <= num; i++) {
		bool flag = false;
		for (int j = 0; j < primes.size() && primes[j] <= sqrt(num) && !flag; j++) {
			if (num % primes[j] == 0)
				flag = true;
		}
		if (!flag) primes[num] = true;
	}

	return primes;
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

