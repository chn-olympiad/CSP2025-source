#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>; 

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
const int M = 3 + 1e6;
const int N = 101 + 1e4;

array<int, 3> e[M], e1[N], e2[N * 11];
int t1, t2;
LL ans;

int n, m, k;
int cost[11];
int a[11][N];

int cmp(array<int, 3> &x, array<int, 3> &y) {
	return x[2] < y[2];
}

namespace DSU {
	int size[N], fa[N];
	void init(int n) {
		for (int i = 1; i <= n; ++i) {
			fa[i] = i;
			size[i] = 1;
		}
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	int same(int u, int v) {
		return find(u) == find(v);
	}
	void merge(int u, int v) {
		if (same(u, v)) {
			return;
		}
		u = find(u);
		v = find(v);
		if (size[u] > size[v]) {
			swap(u, v);
		}
		size[v] += size[u];
		fa[u] = v;
	}
}

void solve(int st) {
	LL cnt = 0;
	
	t2 = 0;
	
	for (int i = 0; i < k; ++i) {
		if (st >> i & 1) {
			cnt += cost[i + 1];
			if (cnt >= ans) {
				return;
			}
			for (int j = 1; j <= n; ++j) {
				e2[++t2] = {i + 1 + n, j, a[i + 1][j]};
			}
		}
	}
	
	for (int i = 1; i <= t1; ++i) {
		e2[++t2] = e1[i];
	}
	sort(e2 + 1, e2 + t2 + 1, cmp);
	DSU::init(n + k);
	
	for (int i = 1; i <= t2; ++i) {
		if (DSU::same(e2[i][0], e2[i][1])) {
			continue;
		}
		DSU::merge(e2[i][0], e2[i][1]);
		cnt += e2[i][2];
		if (cnt >= ans) {
			return;
		}
	}
	
	ans = min(ans, cnt);
}

int main() {
//	freopen("D:\\work\\road2.in", "r", stdin);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> e[i][0] >> e[i][1] >> e[i][2];
	}
	for (int i = 1; i <= k; ++i) {
		cin >> cost[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	sort(e + 1, e + m + 1, cmp);
	
	DSU::init(n);
	for (int i = 1; i <= m; ++i) {
		if (DSU::same(e[i][0], e[i][1])) {
			continue;
		}
		DSU::merge(e[i][0], e[i][1]);
		e1[++t1] = e[i];
		ans += e[i][2];
	}
//	cout << ans << endl; 
	
	for (int i = 1; i < 1 << k; ++i) {
		solve(i);
	}
	cout << ans;
	
	return 0;
}