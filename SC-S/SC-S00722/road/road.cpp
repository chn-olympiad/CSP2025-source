#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6+10;
struct Node {
	int u, v, w;
	const bool operator <(const Node x) {
		return w < x.w;
	}
};
Node a[maxn];
int index_ = 0;
int n, m, k;
int fa[maxn];
int fd(int u) {
	if (fa[u] == u)return u;
	fa[u] = fd(fa[u]);
	return fa[u];
}
void uni(int u, int v) {
	fa[fd(u)] = fd(v);
}
void init() {
	for (int i = 1; i <= n + k + 10; i++)fa[i] = i;
	index_ = 0;
}
void add(int u, int v, int w) {
	a[index_].u = u, a[index_].v = v;
	a[index_].w = w;
	index_++;
}
int U[maxn], V[maxn], W[maxn];
const long long inf = 1e18;
long long ans = inf;
int c[15], to[15][maxn];
int main() {
//	freopen("road2.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> U[i] >> V[i] >> W[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> to[i][j];
		}
	}
	for (int p = 0; p < (1 << k); p++) {
		init();
		for (int i = 1; i <= m; i++) {
			add(U[i], V[i], W[i]);
		}
		long long res = 0;
		for (int i = 0; i < k; i++) {
			if ((1 << i) & p) {
				res += c[i];
				for (int j = 1; j <= n; j++) {
					add(i + n + 1, j, to[i][j]);
				}
			}
		}
		sort(a, a + index_);
		for (int i = 0; i < index_; i++) {
			if (fd(a[i].u) == fd(a[i].v))continue;
			uni(a[i].u, a[i].v);
			res += a[i].w;
		}
		ans = min(ans, res);
	}
	cout << ans;
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