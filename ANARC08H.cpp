#include <iostream>

using namespace std;

typedef struct node_struct {
	int num;
	struct node_struct *next;
} node;

int main() {
	while (true) {
		int n, d; cin >> n >> d;
		if (n == 0 && d == 0) break;

		node *head = new node;
		node *temp = head;

		for (int i = 1; i < n; i++) {
			temp->num = i;
			temp->next = new node;
			temp = temp->next;
		}

		temp->num = n; temp->next = head;

		int count = 0;
		while (true) {
			count ++;
			if (count == d) {
				temp->next = temp->next->next;
				count = 1;
			}

			if (temp->next == temp) {
				cout << n << " " << d <<" "<< temp->num << endl;
				break;
			}
			temp = temp->next;
		}
	}
}
