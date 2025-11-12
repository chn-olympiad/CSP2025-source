# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 1e4 + 5;
const ll M = 1e6 + 5;
ll n, m, mm, k, ans, res = LONG_LONG_MAX;
ll c[N], a[15][N], fa[N];
bool f[N];
struct Node {
	ll u, v, w;
} e[M], ee[N * 10 + M];

bool cmp (Node n1, Node n2) {
	return n1.w < n2.w;
}

ll Find (ll x) {
	if (x == fa[x]) return x;
	return fa[x] = Find (fa[x]);
}

void dfs (ll now) {
	if (now == k + 1) {
		mm = m, ans = 0;
		for (ll i = 1; i <= n; i ++) fa[i] = i;
		for (ll i = 1; i <= m; i ++) ee[i] = e[i];
		for (ll i = 1; i <= k; i ++) {
			if (f[i]) {
				// cout << "添加乡村" << i << "\n";
				ans += c[i];
				fa[n + i] = n + i;
				for (ll j = 1; j <= n; j ++) {
					mm ++;
					ee[mm].u = n + i;
					ee[mm].v = j;
					ee[mm].w = a[i][j];
					// cout << "新增的乡村" << i << "与" << j << "的边\n";
				}
			}
		}
		sort (ee + 1, ee + mm + 1, cmp);
	//  for (ll i = 1; i <= mm; i ++) {
	//		cout << ee[i].u << " " << ee[i].v << " " << ee[i].w << "\n";
	//	} cout << "%%%\n";
		for (ll i = 1; i <= mm; i ++) {
			ll x = ee[i].u, y = ee[i].v;
			x = Find (x), y = Find (y);
			if (x != y) {
				ans += ee[i].w;
				fa[x] = y;
			}
		}
		res = min (res, ans);
		return ;
	}
	f[now] = 1;
	dfs (now + 1);
	f[now] = 0;
	dfs (now + 1);
}

int main () {

	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
    ios::sync_with_stdio (0);
    cin.tie (0), cout.tie (0);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i ++) cin >> e[i].u >> e[i].v >> e[i].w;
	for (ll i = 1; i <= k; i ++) {
		cin >> c[i];
		for (ll j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	if (k <= 5) {
		dfs (1);
		cout << res;
	} else {
		mm = m, ans = 0;
		for (ll i = 1; i <= n; i ++) fa[i] = i;
		for (ll i = 1; i <= m; i ++) ee[i] = e[i];
		sort (ee + 1, ee + mm + 1, cmp);
	//  for (ll i = 1; i <= mm; i ++) {
	//		cout << ee[i].u << " " << ee[i].v << " " << ee[i].w << "\n";
	//	} cout << "%%%\n";
		for (ll i = 1; i <= mm; i ++) {
			ll x = ee[i].u, y = ee[i].v;
			x = Find (x), y = Find (y);
			if (x != y) {
				ans += ee[i].w;
				fa[x] = y;
			}
		}
		cout << ans;
	}

	return 0;
}
// 68
