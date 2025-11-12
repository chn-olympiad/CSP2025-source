#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;

int n, m, k, c[15][N], fa[N], sz, nf[N];
struct node {
	int u, v, w;
	bool operator < (const node &x) const{
		return w < x.w;
	}
} b[M], d[M * 10];
long long res;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int f(int x) {
	return nf[x] == x ? x : nf[x] = f(nf[x]);
}

void dfs(int x) {
	if (x > k) {
		long long ans = 0;
		sort(d + 1, d + sz + 1);
		for (int i = 1; i <= sz; i++) {
			int fx = f(d[i].u), fy = f(d[i].v);
			if (fx != fy) {
				nf[fx] = fy;
				if (1LL * d[i].w > res - ans) {
					return;
				}
				ans += 1LL * d[i].w;
			}
		}
		res = min(res, ans);
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			d[++sz] = (node) {
				i, j, c[x][0] + c[x][i] + c[x][j]
			};
		}
	}
	dfs(x + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			d[sz] = (node) {
				0, 0, 0
			};
			sz--;
		}
		nf[i] = i;
	}
	dfs(x + 1);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> b[i].u >> b[i].v >> b[i].w;
		d[i].u = b[i].u;
		d[i].v = b[i].v;
		d[i].w = b[i].w;
	}
	sz = m;
	for (int i = 1; i <= n; i++) {
		fa[i] = nf[i] = i;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	if (k == 0 || n >= 1000) {
		sort(b + 1, b + m + 1);
		for (int i = 1; i <= m; i++) {
			int fx = find(b[i].u), fy = find(b[i].v);
			if (fx != fy) {
				fa[fx] = fy;
				res += 1LL * b[i].w;
			}
		}
		cout << res;
	} else {
		res = 1e18;
		dfs(1);
		cout << res;
	}
	return 0;
}
