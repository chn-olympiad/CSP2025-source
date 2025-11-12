#include <bits/stdc++.h>
using namespace std;

const int N = 10015, M = 1100010;

int n, m, k, cm;
long long ans;
int fa[N];
struct edge {
	int a, b, c;
}E[M];
bool cmp(edge x, edge y) { return x.c < y.c; }

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[++cm] = {u, v, w};
	}
	for (int i = n + 1; i <= n + k; i++) {
		int c;
		cin >> c;
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			E[++cm] = {i, j, a};
		}
	}
	sort(E + 1, E + cm + 1, cmp);
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	int cnt = 0;
	for (int i = 1; i <= cm; i++) {
		int x = find(E[i].a), y = find(E[i].b);
		if (x != y) {
			fa[x] = y;
			ans += E[i].c, cnt++;
			if (cnt == n + k - 1) break;
		}
	}
	cout << ans;
	return 0;
}
