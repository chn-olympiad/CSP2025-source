#include <iostream>
#include <algorithm>

struct Edge {
	int x;
	int y;
	int val;
} edge[1000001];

int n = 0;
int m = 0;
int k = 0;
int cnt = 0;
int fa[10001] = {};
int head[11] = {};

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

void add_edge(int x, int y, int v) {
	edge[++cnt].x = x;
	edge[cnt].y = y;
	edge[cnt].val = v;
}

bool cmp(Edge x, Edge y) {
	return x.val < y.val;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int tmpx = 0;
		int tmpy = 0;
		int tmpv = 0;
		std::cin >> tmpx >> tmpy >> tmpv;
		add_edge(tmpx, tmpy, tmpv);
	}
	for (int i = 1; i <= k; ++i) {
		head[i] = -1;
		int c = 0;
		std::cin >> c;
		for (int j = 1; j <= n; ++j) {
			int tmp = 0;
			std::cin >> tmp;
			if (!c && !tmp) {
				if (~head[i]) {
					fa[find(j)] = head[i];
				} else {
					head[i] = find(j);
				}
			}
		}
	}
	
	std::sort(edge + 1, edge + m + 1, cmp);
	
	long long ans = 0;
	for (int i = 1; i <= m; ++i) {
		int u = find(edge[i].x);
		int v = find(edge[i].y);
		if (u == v) {
			continue;
		}
		fa[v] = u;
		ans += edge[i].val;
	}
	
	std::cout << ans;
	
	return 0;
}
