void GetLevelCounts(map <int, vector <int> > & tree, map <int, vector <int> > & level_counts, int n) {
	map <int, vector <int> >::iterator it;

	for (int i = n - 1; i >= 0; i--) {
		level_counts[i].push_back(1);

		if ((it = tree.find(i)) != tree.end()) {
			vector <int> children;
			cout << "\nChildren of " << i << ": ";
			for (int j = 0; j < it->second.size(); j++) {
				children.push_back(it->second[j]);
				cout << " " << it->second[j];
			}
			cout << endl << endl;

			level_counts[i].push_back(children.size());

			int max_depth = 0;
			for (int j = 0; j < children.size(); j++) {
				if (max_depth < level_counts[children[j]].size()) max_depth = level_counts[children[j]].size();
			}
			cout << "max depth: " << max_depth << endl;


			for (int k = 1; k < max_depth; k++) {
				level_counts[i].push_back(0);
				for (int p = 0; p < children.size(); p++) {
					if (k < level_counts[children[p]].size())
						level_counts[i][k + 1] += level_counts[children[p]][k];
				}
			}
		}

	}
}
