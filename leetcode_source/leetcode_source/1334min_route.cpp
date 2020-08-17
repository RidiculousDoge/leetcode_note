#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

void dfs(int last_node, int cur_node, vector<set<int>>& ls, vector<vector<vector<int>>> graph, int distanceThreshold) {
	if (distanceThreshold < 0) return;
	if (cur_node != last_node) {
		ls[last_node].insert(cur_node);
	}
	vector<vector<int>> tmp = graph[cur_node];
	for (int i = 0; i < tmp.size(); i++) {
		dfs(last_node, tmp[i][0], ls, graph, distanceThreshold - tmp[i][1]);
	}
}
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
	vector<set<int>> canMake(n);
	vector<vector<vector<int>>> graph(n);
	//build a graph
	for (int i = 0; i < edges.size(); i++) {
		vector<int> tmp = { edges[i][1],edges[i][2] };
		vector<int> tmp2 = { edges[i][0],edges[i][2] };
		graph[edges[i][0]].push_back(tmp);
		graph[edges[i][1]].push_back(tmp2);
	}

	for (int i = 0; i < n; i++) {
		dfs(i, i, canMake, graph, distanceThreshold);
	}
	int min_sum = canMake[0].size();
	int index = 0;
	for (int i = 1; i < canMake.size(); i++) {
		if (canMake[i].size() <= min_sum) {
			index = i;
			min_sum = canMake[i].size();
		}
	}
	return index;
}
