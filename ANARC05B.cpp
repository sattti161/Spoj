#include <iostream>
#include <vector>

using namespace std;

vector <long long int> GetCommonPoints(long long int *arr1, long long int *arr2, long long int size1, long long int size2);
long long int GetMaxSum(long long int *arr1, long long int *arr2, long long int size1, long long int size2);

int main() {
	vector <long long int> answers;
	while (true) {
		long long int size1, size2;
		cin >> size1;
		if (size1 == 0) break;
		long long int arr1[size1];
		for (long long int i = 0; i < size1; i++) cin >> arr1[i];

		cin >> size2; long long int arr2[size2];
		for (long long int i = 0; i < size2; i++) cin >> arr2[i];

		answers.push_back(GetMaxSum(arr1, arr2, size1, size2));
	}

	for (long long int i = 0; i < answers.size(); i++) cout << answers[i] << endl;
}


vector <long long int> GetCommonPoints(long long int *arr1, long long int *arr2, long long int size1, long long int size2) {
	vector <long long int> common_points;
	long long int i = 0, j = 0;
	while (true) {
		if (i >= size1 || j >= size2) break;
		while (i < size1 && j < size2 && arr1[i] <= arr2[j]) {
			if (arr1[i] == arr2[j]) common_points.push_back(arr1[i]);
			i++;
		}

		while (i < size1 && j < size2 && arr2[j] <= arr1[i]) {
			if (arr1[i] == arr2[j]) common_points.push_back(arr1[i]);
			j++;
		}
	}

	return common_points;
}


long long int GetMaxSum(long long int *arr1, long long int *arr2, long long int size1, long long int size2) {
	vector <long long int> common_points = GetCommonPoints(arr1, arr2, size1, size2);
	long long int i = 0, j = 0, k = 0, sum = 0, sum1, sum2;

	while (k < common_points.size()) {
		sum1 = sum2 = 0;
		while (i < size1) {
			sum1 += arr1[i];
			if (arr1[i] == common_points[k]) {
				i++; break;
			}
			i++;
		}
		while (j < size2) {
			sum2 += arr2[j];
			if (arr2[j] == common_points[k]) {
				j++; break;
			}
			j++;
		}
		k++;

		if (sum1 >= sum2) sum += sum1;
		else sum += sum2;
	}

	sum1 = sum2 = 0;
	for (; i < size1; i++) sum1 += arr1[i];
	for (; j < size2; j++) sum2 += arr2[j];

	if (sum1 >= sum2) sum += sum1;
	else sum += sum2;

	return sum;
}

