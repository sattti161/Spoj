#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
	while (true) {
		int v, e; cin >> v;
		if (v == 0) break;
		cin >> e;

		map <int, vector <int> > graph, level_counts;

		for (int j = 0; j < e; j++) {
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			graph[v1].push_back(v2);
		}
	}
}

vector <int> GetSinks(map <int, vector <int> > & graph, int v) {
	vector <int> sinks;
	for (int i = 1; i <= v; i++) {
		IsSink(graph, i);
	}
}


bool IsSink(map <int, vector <int> > & graph, int cur_node) {
	map <int, vector <int> >::iterator it;
	vector <int> stack; stack.push_back(cur_node);


}
