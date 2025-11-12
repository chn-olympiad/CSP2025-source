#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
using i64 = long long;
using pii = pair<int, int>;

const int N = 1E4 + 10, M = 1E6 + 10;

bool ST;
int n, m, k;
array<int, 3> e[M], ne[10][N], me[N * 2];
int cost[10], dsu[N];
array<int, 3> mst[1 << 10][N];
bool ED;

int find(int x) {
	if (dsu[x] != x) dsu[x] = find(dsu[x]);
	return dsu[x];
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i ++)
		cin >> e[i][1] >> e[i][2] >> e[i][0];
	sort(e + 1, e + 1 + m);
	
	iota(dsu, dsu + n + 1, 0);
	int idx = 0;
	i64 ans = 0;
	for (int i = 1; i <= m; i ++) {
		int pu = find(e[i][1]), pv = find(e[i][2]);
		if (pu != pv) {
			dsu[pu] = pv;
			mst[0][ ++ idx] = e[i];
			ans += e[i][0];
		}
	}
	
	for (int i = 0; i < k; i ++) {
		cin >> cost[i];
		vector<pii> a(n + 1);
		for (int j = 1; j <= n; j ++)
			cin >> a[j].fi, a[j].se = j;
		sort(a.begin() + 1, a.end());
		cost[i] += a[1].fi;
		for (int j = 2; j <= n; j ++)
			ne[i][j - 1] = {a[j].fi, a[j].se, a[1].se};
		sort(ne[i] + 1, ne[i] + n);
	}
	
	for (int i = 1; i < 1 << k; i ++) {
		int j = i ^ (i & -i), id = __lg(i & -i);
		merge(mst[j] + 1, mst[j] + n, ne[id] + 1, ne[id] + n, me + 1);
		i64 res = 0;
		for (int o = 0; o < k; o ++)
			if (i >> o & 1) res += cost[o];
		idx = 0;
		iota(dsu, dsu + n + 1, 0);
		for (int o = 1; o <= 2 * (n - 1); o ++) {
			int pu = find(me[o][1]), pv = find(me[o][2]);
			if (pu != pv) {
				dsu[pu] = pv;
				res += me[o][0];
				mst[i][ ++ idx] = me[o];
			}
		}
		ans = min(ans, res);
	}
	
	cout << ans << '\n';
	
	return 0;
}
