#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <char> ConvertToPostFix(string exp);
void Print(vector<char>stack, vector<char>result);

int main(int argc, char *argv[]) {
	int t; cin >> t;
	vector <vector <char> > answers;
	string exp;
	getline(cin, exp);

	for (int i = 0; i < t; i++) {
		getline(cin, exp);
		answers.push_back(ConvertToPostFix(exp));
	}

	for (int i = 0; i < answers.size(); i++) {
		for (int j = 0; j < answers[i].size(); j++)
			cout << answers[i][j];
		cout << endl;
	}
}


vector <char> ConvertToPostFix(string exp) {
	vector <char> stack, result;

	for (int i = 0; i < exp.size(); i++) {
		//Print(stack, result);
		if (exp[i] == '(' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
			stack.push_back(exp[i]);

		else if (exp[i] == ')') {
			result.push_back(stack[stack.size() - 1]);
			stack.erase(stack.begin() + stack.size() - 1);
			if (stack[stack.size() - 1] == '(')
				stack.erase(stack.begin() + stack.size() - 1);
		}

		else result.push_back(exp[i]);
	}

	return result;
}


void Print(vector<char>stack, vector<char>result) {
	cout << "The stack is: ";
	for (int i = 0; i < stack.size(); i++)
		cout << stack[i];
	cout << endl << "The Result is: ";

	for (int i = 0; i < result.size(); i++)
		cout << result[i];
	cout << endl << endl;

}
