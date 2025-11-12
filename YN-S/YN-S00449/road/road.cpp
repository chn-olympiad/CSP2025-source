#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int MAXE = 1000000 + 10 * 10000 + 10;

struct Edge {
	int u, v;
	long long w;
	Edge(int u_, int v_, long long w_) : u(u_), v(v_), w(w_) {}
	bool operator<(const Edge &other) const {
		return w < other.w;
	}
};

vector<Edge> edges;
int parent[MAXN];
int rank_[MAXN];
int n, m, k;


void init() {
	for (int i = 1; i <= n + k; ++i) {
		parent[i] = i;
		rank_[i] = 1;
	}
}


int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}


bool unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	if (rank_[x] < rank_[y])
		swap(x, y);
	parent[y] = x;
	if (rank_[x] == rank_[y])
		rank_[x]++;
	return true;
}


bool is_all_connected() {
	int root = find(1);
	for (int i = 2; i <= n; ++i) {
		if (find(i) != root)
			return false;
	}
	return true;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}

	for (int j = 1; j <= k; ++j) {
		long long cj;
		cin >> cj;
		int town_node = n + j;

		edges.emplace_back(town_node, 1, cj);

		for (int i = 1; i <= n; ++i) {
			long long aj_i;
			cin >> aj_i;
			edges.emplace_back(town_node, i, aj_i);
		}
	}


	init();
	sort(edges.begin(), edges.end());
	long long total_cost = 0;
	int edges_used = 0;
	for (const auto &e : edges) {
		if (unite(e.u, e.v)) {
			total_cost += e.w;
			edges_used++;

			if (edges_used >= n - 1 && is_all_connected()) {
				break;
			}
		}
	}


	cout << total_cost << endl;

	return 0;
}
