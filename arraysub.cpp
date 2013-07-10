#include <iostream>
#include <vector>

using namespace std;
void PrintVector(vector <int> temp_vec);
vector <int> GetResultArray(int *arr, int size, int k);
void Push(vector <int> & stack, vector <int> & max_arr, int num);
int Pop(vector <int> & stack, vector <int> & max_arr);
void Enqueue(vector<int> & stack1, vector <int> & max1_arr, int num);
int Dequeue(vector<int> & stack1, vector<int> & stack2, vector <int> & max1_arr, vector <int> & max2_arr);
void TestStack(int *arr, int size);


int main(int argc, char *argv[]) {
	int n, k; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;

	//TestStack(arr, n);
	vector <int> answers = GetResultArray(arr, n, k);

	for (int i = 0; i < answers.size(); i++)
		cout << answers[i] << " ";
	cout << endl;
	return 0;
}


void TestStack(int *arr, int size) {
	vector <int> stack, max;
	for (int i = 0; i < size; i++)
		Push(stack, max, arr[i]);
	for (int i = 0; i < max.size(); i++)
		cout << max[i] << " ";
	cout << endl;

	for (int i = 0; i < size; i++) {
		int temp = Pop(stack, max);
	for (int i = 0; i < max.size(); i++)
		cout << max[i] << " ";
	cout << endl;
	}
}

void PrintVector(vector <int> temp_vec) {
	for (int i = 0; i < temp_vec.size(); i++)
		cout << temp_vec[i] << " ";
	cout << endl << endl;
}


vector <int> GetResultArray(int *arr, int size, int k) {
	vector <int> stack1, stack2, max_arr1, max_arr2, answers;
	for (int i = 0; i < k; i++)
		Enqueue(stack1, max_arr1, arr[i]);

	for (int i = k; i <= size; i++) {
		int max, max1, max2;
		bool flag1 = false, flag2 = false;

		if (max_arr1.size() > 0) {
			max1 = max_arr1[max_arr1.size() - 1];
			flag1 = true;
		}
		if (max_arr2.size() > 0) {
			max2 = max_arr2[max_arr2.size() - 1];
			flag2 = true;
		}

		if (flag1 && flag2) {
			if (max1 >= max2) max = max1;
			else max = max2;
		}

		if (flag1 && !flag2) max = max1;
		if (!flag1 && flag2) max = max2;

		answers.push_back(max);
		Dequeue(stack1, stack2, max_arr1, max_arr2);
		Enqueue(stack1, max_arr1, arr[i]);
	}

	return answers;
}


void Push(vector <int> & stack, vector <int> & max_arr, int num) {
	stack.push_back(num);
	max_arr.push_back(num);
	if (max_arr.size() > 1) {
		if (max_arr[max_arr.size() - 2] < num)
			max_arr[max_arr.size() - 1] = num;
		else max_arr[max_arr.size() - 1] = max_arr[max_arr.size() - 2];
	}
}


int Pop(vector <int> & stack, vector <int> & max_arr) {
	int temp = stack[stack.size() - 1];
	stack.erase(stack.begin() + stack.size() - 1);
	max_arr.erase(max_arr.begin() + max_arr.size() - 1);
	return temp;
}




void Enqueue(vector<int> & stack1, vector <int> & max1_arr, int num) {
	Push(stack1, max1_arr, num);
}

int Dequeue(vector<int> & stack1, vector<int> & stack2, vector <int> & max1_arr, vector <int> & max2_arr) {
	if (stack2.size() > 0)
		return Pop(stack2, max2_arr);

	for (int i = stack1.size() - 1; i > 0; i--)
		Push(stack2, max2_arr, stack1[i]);

	int temp = stack1[0];
	vector <int> temp_vec;
	stack1 = max1_arr = temp_vec;
	return temp;
}

