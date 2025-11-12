#include  <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;
#define fi first
#define se second
const int M = 1e6 + 5;
const int N = 1e5 + 5;
ll n, m, k;
struct Edge{
	ll u, v, w;
}e[M << 1], E[M << 1];
int a[11][N], f[N], c[N], cnt, ct;
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
bool cmp(Edge a, Edge b) { return a.w < b.w; }

ll Kru(int SUM) {
	int sum = 0;
	ll res = 0;
	for(int i = 1; i <= cnt; i ++) {
		int u = find(E[i].u), v = find(E[i].v);
		ll w = E[i].w;
		if(u == v) continue;
		res += w; sum ++;
		f[u] = v;
		if(sum == SUM - 1) return res;
	}
	return res;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	bool flag = 0;
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		if(c[i]) flag = 1;
		for(int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	if(!flag) {
		ll ans = 1e18;
		cnt = m, ct = n + k; ll sum = 0;
		for(int j = 1; j <= m; j ++) E[j] = e[j];
		for(int j = 1; j <= k; j ++) {
			for(int o = 1; o <= n; o ++) {
				E[++ cnt] = {j + n, o, a[j][o]};
			}
		}
		for(int j = 1; j <= n + k; j ++) f[j] = j;
		sort(E + 1, E + cnt + 1, cmp);
		sum += Kru(ct);
		ans = min(ans, sum);
		cout << ans << '\n';
		return 0;
	}
	ll ans = 1e18;
	for(int i = 0; i < (1 << k); i ++) {
		cnt = m, ct = n; ll sum = 0;
		for(int j = 1; j <= m; j ++) E[j] = e[j];
		for(int j = 1; j <= k; j ++) {
			if((i >> j - 1) & 1) {
				ct ++; sum += c[j];
				for(int o = 1; o <= n; o ++) {
					E[++ cnt] = {j + n, o, a[j][o]};
				}
			}
		}
		for(int j = 1; j <= n + k; j ++) f[j] = j;
		sort(E + 1, E + cnt + 1, cmp);
		sum += Kru(ct);
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}

