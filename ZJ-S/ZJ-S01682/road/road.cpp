#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 1000, M = 2e6 + 5;
int n, m, K;
int a[11][N], c[11], f[N], num[N];
bool fob[N];
struct Edge {
	int u, v, w;
	bool operator < (const Edge& x) const {
		return w < x.w;
	}
} t[M];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

bool cmp(int a, int b) {
	return c[a] > c[b];
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> K;
	int eg_cnt = 0, cost = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		t[++ eg_cnt] = {u, v, w};
	}
	for (int i = 1; i <= K; ++i) {
		cin >> c[i];
		cost += c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			t[++ eg_cnt] = {i + n, j, a[i][j]};
		}
	}
	sort(t + 1, t + eg_cnt + 1);
	for (int i = 1; i <= n + K; ++i) f[i] = i;
	int cnt = 0;
	for (int i = 1; i <= eg_cnt; ++i) {
		int fu = find(t[i].u), fv = find(t[i].v);
		if(fu == fv) continue;
		++ cnt;
		cost += t[i].w;
		f[fu] = fv;
		if(cnt == n + K - 1) break;
	}
	for (int i = 1; i <= K; ++i) num[i] = i;
	sort(num + 1, num + K + 1, cmp);
//	int num[15] = {0, 2, 4, 5, 6, 7, 8, 9, 10, 1, 3};
	for (int ii = 1, i; ii <= K; ++ii) {
		i = num[ii];
		int res = 0;
		fob[i + n] = true;
		for (int i = 1; i <= n + K; ++i) f[i] = i;
		for (int i = 1; i <= K; ++i) res += c[i] * (!fob[i + n]);
		int cnt = 0;
		for (int i = 1; i <= eg_cnt; ++i) {
			if(fob[t[i].u] || fob[t[i].v]) continue;
			int fu = find(t[i].u), fv = find(t[i].v);
			if(fu == fv) continue;
			++ cnt;
			res += t[i].w;
			f[fu] = fv;
			if(cnt == n + K - 1) break;
		}
		if(res <= cost) cost = res;
		else fob[i + n] = false;
	}
	cout << cost << '\n';
//	for (int i = 1; i <= K; ++i) cout << fob[i + n];
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
