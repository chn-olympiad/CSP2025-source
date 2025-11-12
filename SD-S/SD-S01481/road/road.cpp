#include<bits/stdc++.h>
#define endl '\n'
//#define MSOD

using namespace std;
using ll = long long;

constexpr ll N = 2e4 + 5, M = 2e6 + 5;

bool ST;
ll n, m, k;
struct edge {
	ll u, v, w;
	edge() {}
	edge(ll a, ll b, ll c) : u(a), v(b), w(c) {}
	inline friend bool operator < (edge x, edge y) {
		return x.w < y.w;
	}
} edg[M], nedg[M];
ll fa[N], c[15], a[15][N];

bool ED;
inline ll fnd(ll x) {
	return (x == fa[x] ? x : fa[x] = fnd(fa[x]));
}
inline void task1() {
	ll tot = m;
	for(int i = 1 ; i <= k ; i ++) {
		for(int j = 1 ; j <= n ; j ++) {
			edg[++ tot] = edge(n + i, j, a[i][j]);
		}
	}
	sort(edg + 1, edg + tot + 1);
	iota(fa + 1, fa + n + k + 1, 1ll);
	ll ans = 0;
	for(int i = 1 ; i <= tot ; i ++) {
		ll fu = fnd(edg[i].u), fv = fnd(edg[i].v);
		if(fu != fv) {
			ans += edg[i].w;
			fa[fu] = fv;
		}
	}
	cout<<ans<<endl;
	return;
}
inline void solve() {
	cin>>n>>m>>k;
	for(int i = 1 ; i <= m ; i ++) {
		cin>>edg[i].u>>edg[i].v>>edg[i].w;
	}
	bool ok = true;
	for(int i = 1 ; i <= k ; i ++) {
		cin>>c[i];
		ok &= (c[i] == 0);
		for(int j = 1 ; j <= n ; j ++) {
			cin>>a[i][j];
		}
	}
	if(k == 0 || ok) {
		task1();
	} else {
		ll ans = LLONG_MAX; 
		for(int S = 0 ; S < (1ll << k) ; S ++) {
			iota(fa + 1, fa + n + k + 1, 1ll);
			ll tot = 0, sm = 0;
			for(int i = 1 ; i <= m ; i ++) {
				nedg[++ tot] = edg[i];
			}
			for(int i = 0 ; i < k ; i ++) {
				if(S & (1ll << i)) {
					sm += c[i + 1];
					for(int j = 1 ; j <= n ; j ++) {
						nedg[++ tot] = edge(n + i + 1, j, a[i + 1][j]);
					}
				}
			}
			sort(nedg + 1, nedg + tot + 1);
			for(int i = 1 ; i <= tot ; i ++) {
				ll fu = fnd(nedg[i].u), fv = fnd(nedg[i].v);
				if(fu != fv) {
					fa[fu] = fv;
					sm += nedg[i].w;
				}
			}
			ans = min(ans, sm);
		}
		cout<<ans<<endl;
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int TC = 1;
#ifdef MSOD
	cin>>TC;
#endif
	while(TC --) {
		solve();
	}
	return 0;
}

