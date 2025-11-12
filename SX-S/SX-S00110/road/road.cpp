#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+5, M = 1e6+5;
int n, m, k, f[N], sz[N], c[N], d[10][N], ans;

struct edge {
	int s, t, w;
} e[M];

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int find(int p) {
	if (p != f[p])
		f[p] = find(f[p]);
	return f[p];
}

int union1(int a, int b) {
	int fa = find(a), fb = find(b);
	if (fa == fb)
		return -1;
	if (sz[fa] > sz[fb]) {
		sz[fa] += sz[fb];
		f[fb] = fa;
		return sz[fa];
	} else {
		sz[fb] += sz[fa];
		f[fa] = fb;
		return sz[fb];
	}
}

void K() {
	sort(e, e + m, cmp);
	for (int i = 0; i < m; i++) {
		edge z = e[i];
		int s = union1(z.s, z.t);
		if (s == -1)
			continue;
		ans += z.w;
		if (s == n)
			return;
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		f[i] = i, sz[i] = 1;
	for (int i = 0; i < m; i++)
		cin >> e[i].s >> e[i].t >> e[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}
	K();
	cout << ans;
	return 0;
}
