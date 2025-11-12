#include <bits/stdc++.h>
//是最小生成树
//先写并查集
#define s second
#define f first
using namespace std;
const int N = 1e4 + 5;
const int K = 15;
//i->j的边权
int M[N + K][2 * N], MK[K][N], CK[K];
//f指向 s大小
vector<pair<int, int>> bcj;

int find(int node) {
	if (bcj[node].f == 100000000)
		return node;
	else {
		node = bcj[node].first;
		return find(node);
	}
}

void hebing(int root1, int root2) {
	if (bcj[root1].s > bcj[root2].s) {
		bcj[root2].f = root1;
		bcj[root1].s += bcj[root2].s;
	} else {
		bcj[root1].f = root2;
		bcj[root2].s += bcj[root1].s;
		bcj[root1].s += bcj[root2].s;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;
	//权 i to
	vector<pair<int, pair<int, int>>>edges;
	for (int e = 0; e < m; e++) {
		int u, v, w;
		cin >> u >> v;
		cin >> w;
		M[u][v] = w;
		edges.push_back({w, {u, v}});
	}

	for (int u = 0; u < k; u++) {
		cin >> CK[u];
		for (int v = 0; v < n; v++) {
			cin >> MK[u][v];
		}
	}

	sort(edges.begin(), edges.end());
	bcj = vector<pair<int, int>>(n, {100000000, 1});
	vector<vector<int>>tree;
	long long ans = 0;
	for (int j = 0; j < m; j++) {
		int i = edges[j].s.f;
		int to = edges[j].s.s;
		int root1 = find(i);
		int root2 = find(to);
		if (root1 != root2) {
			hebing(root1, root2);
			ans += edges[j].f;
		}
	}
	cout << ans << endl;
}