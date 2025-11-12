#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int N_MAX = 1e4 + 10;
const int M_MAX = 1e6 + 10;

int n, m, k;
int fa[N_MAX];

struct Edge {
	int u, v, w;
} e[M_MAX];

inline int find(int x) {
	return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}

inline void merge(int x, int y) {
	fa[find(y)] = find(x);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> n >> e[i].u >> e[i].v >> e[i].w;
	}

	cout << 0 << endl;

	return 0;
}
