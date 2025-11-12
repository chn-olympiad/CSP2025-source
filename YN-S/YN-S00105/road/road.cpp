#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n, m, k;
int u[N], v[N], w[N], f[10005];
vector<pair<int, int>> adj[N];
int a[15][10005];
int c[15];

struct node {
	int u, v, w;
} edge[N];

bool cmp(node x, node y) {
	return x.w < y.w;
}

int fnd(int x) {
	if (x == f[x])
		return f[x];
	f[x] = fnd(f[x]);
	return f[x];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = m;
	for (int i = 1; i <= m; i++) {
		int tmp = w[i];
		for (int j = 1; j <= k; j++) {
			tmp = min(tmp, a[j][u[i]] + a[j][v[i]]);
		}
		edge[i] = {u[i], v[i], tmp};
	}
	sort(edge + 1, edge + m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int x = edge[i].u, y = edge[i].v;
		//cout << x << " " << y << endl;
		if (fnd(x) != fnd(y)) {
			ans += edge[i].w;
			f[x] = y;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
/*
4 4 0
1 4 6
3 4 4
2 4 5
2 3 7
*/