#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5, maxm = 1e6 + 5, maxk = 12;
int n, m, k;

struct Edge {
	int x, y, w;
} edge[maxm];
int c[maxk][maxn];

struct Node {
	int x, w;
};
vector<Node> G[maxn];
int fa[maxn];

int find(int x) {
	if (x == fa[x])
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy)
		return;
	fa[fx] = fy;
}

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

int kruscal() {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	int sum = 0;
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1; i <= n; i++) {
		int x = edge[i].x, y = edge[i].y, w = edge[i].w;
		if (find(x) != find(y)) {
			merge(x, y);
			G[x].push_back({y, w});
			G[y].push_back({x, w});
			sum += w;
		}
	}
	return sum;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edge[i] = {x, y, w};
	}
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	}
	cout << kruscal();
	fclose(stdin);
	fclose(stdout);
	return 0;
}