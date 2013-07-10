#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

struct temp_node{
	int node_id;
	vector <struct temp_node*> children;
	struct temp_node *parent;
};

typedef struct temp_node node;
void GetLevelCounts(map <int, vector <int> > & tree, map <int, vector <int> > & level_counts, int n);
vector <long long int> GetLevelSum(map <int, vector <int> > & tree, map <int, vector <int> > & level_counts, int n, int k);
long long int GetSumForNode(int node, map <int, vector <int> > & level_counts, vector <int> & stack, int k);

int main(int argc, char *argv[]) {
	int t; cin >> t;
	vector <vector <long long int> > answers;

	for (int i = 0; i < t; i++) {
		int n, k; cin >> n >> k;
		vector <pair <int, int> > edges;
		map <int, vector <int> > tree, level_counts;

		for (int j = 0; j < n - 1; j++) {
			int v1, v2;
			cin >> v1 >> v2;
			if (v1 < v2) tree[v1].push_back(v2);
			else tree[v2].push_back(v1);
		}

		GetLevelCounts(tree, level_counts, n);
		/*for (map <int, vector <int> >::iterator it = level_counts.begin(); it != level_counts.end(); it++) {
			cout << it->first << "->>>>>> ";
			for (int j = 0; j < it->second.size(); j++) cout << it->second[j] << " ";
			cout << endl;
		} */

		answers.push_back(GetLevelSum(tree, level_counts, n, k));
	}

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < answers[i].size(); j++) cout << answers[i][j] << endl;
		cout << endl;
	}
}



void GetLevelCounts(map <int, vector <int> > & tree, map <int, vector <int> > & level_counts, int n) {
	map <int, vector <int> >::iterator it;

	for (int i = n - 1; i >= 0; i--) {
		level_counts[i].push_back(1);

		if ((it = tree.find(i)) != tree.end()) {
			level_counts[i].push_back(it->second.size());

			int max_depth = 0;
			for (int j = 0; j < it->second.size(); j++) {
				if (max_depth < level_counts[it->second[j]].size()) max_depth = level_counts[it->second[j]].size();
			}
			//cout << "max depth: " << max_depth << endl;


			for (int k = 1; k < max_depth; k++) {
				level_counts[i].push_back(0);
				for (int p = 0; p < it->second.size(); p++) {
					if (k < level_counts[it->second[p]].size())
						level_counts[i][k + 1] += level_counts[it->second[p]][k];
				}
			}
		}

	}
}



vector <long long int> GetLevelSum(map <int, vector <int> > & tree, map <int, vector <int> > & level_counts, int n, int k) {
	vector <long long int> sums;
	vector <int> stack; stack.push_back(0);
	for (int i = 0; i < n; i++) sums.push_back(0);

	while (stack.size() > 0) {
		int cur = stack[stack.size() - 1];

		if (tree[cur].size() == 0) {
			sums[cur] = GetSumForNode(cur, level_counts, stack, k);
			stack.erase(stack.begin() + stack.size() - 1);
			continue;
		}

		stack.push_back(tree[cur][tree[cur].size() - 1]);
		tree[cur].erase(tree[cur].begin() + tree[cur].size() - 1);
	}

	return sums;
}


long long int GetSumForNode(int node, map <int, vector <int> > & level_counts, vector <int> & stack, int k) {
	//cout << "Current Node: " << node << " and the parents are: ";
	//for (int i = 0; i < stack.size(); i++) cout << stack[i] << " ";
	//cout << endl << endl;

	int cur_depth = stack.size() - 1;
	long long int sum = 0;
	for (int parent = stack.size() - 1; parent >= 0; parent--) {
		//cout << "Current Parent Max Depth: " << level_counts[parent].size() << endl << endl;
		for (int level = 0; level < level_counts[stack[parent]].size(); level++) {
			//cout << "Current Parent: " << stack[parent] << " Current Level: " << level  << " Count at level: " << level_counts[stack[parent]][level] << endl;
			if (level > 0 && parent < stack.size() - 1) {
				//cout << "level: " << cur_depth - parent + level + 1 << " Num nodes: " << level_counts[stack[parent]][level] << "  " << level_counts[stack[parent + 1]][level - 1] << endl;
				sum += (level_counts[stack[parent]][level] - level_counts[stack[parent + 1]][level - 1]) * (long long int)(pow ( cur_depth -  parent + level + 1, k));
			}
			else {
				//cout << "level: " << cur_depth - parent + level + 1 << " Num nodes: " << level_counts[stack[parent]][level] << endl;
				sum += level_counts[parent][level] * (long long int)(pow ( cur_depth -  parent + level + 1, k));
			}
		}
	}

	//cout << "The sum for node :" << node << " is: " << sum << endl;
	return sum;
}



/*
void GenerateGraph(vector <pair <int, int> > edges) {
	node * head;

}


vector <int> GetNeighbors(int cur_node, vector <pair <int, int> > edges) {

}
*/
