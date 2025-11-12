#include <bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define int long long
#define pii pair <int , int>
#define pip pair <ll , pii >
#define mkp make_pair
#define fi first
#define se second

const int N = 2e6 + 5 , M = 1e5 + 5;

int fa[M] , n , m , k , cnt;
ll ans = 1e18;
int det , a[15][M] , c[M];

set <pip> e;

struct edge {
	int u , v , w;
}E[N];

inline int find (int x) {
	if (x == fa[x]) return x;
	return fa[x] = find (fa[x]);
}

void adde (int u , int v , int w) {
	E[++ cnt].u = u;
	E[cnt].v = v;
	E[cnt].w = w;
}

bool cmp (edge a , edge b) {
	return a.w < b.w;
}

void solve () {
	for (int i = 1;i <= n + k;i ++) fa[i] = i;
	stable_sort (E + 1 , E + 1 + cnt , cmp);
	int tot = 0 , res = 0;
	for (int i = 1;i <= cnt;i ++) {
		int u = find (E[i].u) , v = find (E[i].v);
		if (u == v) continue; fa[u] = v; tot ++;
		res += E[i].w; if (tot == n + k - 1) break;
	}
	cout << res;
}

inline void kruskal (int S) {
	ll tot = 0 , res = 0 , sum = __builtin_popcount(S);
	for (re int i = 0;i <= n + k;i ++) fa[i] = i;
	for (re int i = 1;i <= k;i ++) {
		if (S & (1 << (i - 1))) res += c[i];
	} 
	for (auto i = e.begin();i != e.end();i ++) {
		auto tmp = *i;
		int u = find (tmp.se.fi) , v = find (tmp.se.se);
		if (u == v) continue; 
		fa[u] = fa[v];
		tot ++; res += tmp.fi;
		if (res >= ans) return ;
		if (tot == n + sum - 1) break;
	}
	ans = min (ans , res);
}

signed main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for (re int i = 1;i <= m;i ++) {
		int u , v , w;
		cin >> u >> v >> w;
		e.insert (mkp (w , mkp (u , v)));
		adde (u , v , w);
	}
	int sumc = 0;
	for (re int i = 1;i <= k;i ++) {
		cin >> c[i]; sumc += c[i];
		for (int j = 1;j <= n;j ++) cin >> a[i][j] , adde (n + i , j , a[i][j]);
	}
	if (sumc == 0) {
		solve ();
		return 0;
	}
	for (re int S = 0;S < (1 << k);S ++) {
		for (re int i = 1;i <= k;i ++) {
			if (S & (1 << (i - 1))) {
				if (S && ((S - 1) & (1 << (i - 1))));
				else for (re int j = 1;j <= n;j ++) e.insert (mkp (a[i][j] , mkp (j , n + i)));
			}
		}
		kruskal (S);
		if (S == ((1 << k) - 1)) break;
		for (re int i = 1;i <= k;i ++) {
			if (S & (1 << (i - 1))) {
				if (!((S + 1) & (1 << (i - 1))))
					for (int j = 1;j <= n;j ++) e.erase (mkp (a[i][j] , mkp (j , n + i)));
			}
		}
	}
	cout << ans;
	return 0;
}