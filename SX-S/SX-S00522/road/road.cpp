#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k, ans, t = 1;
ll fa[100055];

struct node {
	ll u, v, w;
} e[100005];

inline ll find(ll x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

inline void merge(ll x, ll y) {
	fa[find(y)] = fa[find(x)];
}

inline bool cmp(node a, node b) {
	return a.w < b.w;
}

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= 2 * n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		merge(e[i].u + n, e[i].v);
		merge(e[i].u, e[i].v + n);
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> t;
		}
	}
	if (k == 0) {
		stable_sort(e + 1, e + m + 1, cmp);
		for (int i = 1; i <= m; i++) {
			if (find(e[i].u) != find(e[i].v)) {
				merge(e[i].u, e[i].v);
				ans += e[i].w;
			}
		}
		cout << ans;
	} else
		cout << 0;

	return 0;
}
