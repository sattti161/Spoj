#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
	vector<int>answers;

	while (true) {
		string temp;
		vector<char> stack;
		getline(cin, temp);

		if (temp[0] == '-')
			break;
		int count = 0;

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == '{')
				stack.push_back('{');
			if (temp[i] == '}') {
				if (stack.size() > 0)
					stack.erase(stack.begin() + stack.size() - 1);
				else {
					stack.push_back('{');
					count ++;
				}
			}
		}

		answers.push_back(count + stack.size() / 2);
	}

	for (int i = 0; i < answers.size(); i++)
		cout << i + 1 << ". " << answers[i] << endl;
}
