#include <bits/stdc++.h>
using namespace std;

struct Edge {

	int from, cost, to;
	bool operator<(const Edge &other)const {
		return cost < other.cost;
	}
};

int find(int x, vector<int> &parent) {
	if (parent[x] != x) {
		parent[x] = find(parent[x], parent);
	}
	return parent[x];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int city_num, road_num, town_num;
	cin >> city_num >> road_num >> town_num;
	vector<Edge> edges;
	for (int i = 0; i < road_num; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edges.push_back({from, to, cost});
	}
	for (int j = 0; j < town_num; j++) {
		int town_cost;
		cin >> town_cost;
		vector<int>build_cost(city_num);
		for (int i = 0; i < city_num; i++) {
			cin >> build_cost[i];
			edges.push_back({0, i + 1, town_cost + build_cost[i]});
		}
	}
	sort(edges.begin(), edges.end());
	vector<int>parent(city_num + 1);
	for (int i = 0; i <= city_num; i++) {
		parent[i] = i;
	}
	int total = 0;
	for (const Edge &e : edges) {
		int u = e.from;
		int v = e.to;
		int c = e.cost;
		if (find(u, parent) != find(v, parent)) {
			parent[find(u, parent)] = find(v, parent);
			total += c;
		}
	}
	cout << total << endl;
	return 0;
}
