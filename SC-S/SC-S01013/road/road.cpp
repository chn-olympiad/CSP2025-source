#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l;i <= r;++ i)
using ll = long long;
using namespace std;
using P = pair<int, ll>;
int tt;
namespace wangcy {
	const int N = 1e6 + 10, anotherN = 1e5 + 10;
	const ll inf = 1e18;
	int n, m, k, v;
	ll a[13][anotherN], c[N], f[N];
	ll ans = inf;
	vector <P> g[13];
	bitset <N> bit;
	struct edge {
		ll u, v, w;
		bool operator < (const edge& t) const { return w < t.w; }
	}e[N], e2[N], tmp[N];
	int gf(int x) {
		return x == f[x] ? x: f[x] = gf(f[x]);
	}
	inline void link(int u, int v2) {
		int x = gf(u), y = gf(v2);
		if(x == y) return;
		f[x] = y;
	}
	inline void Main() {
		cin >> n >> m >> k;
		E(i, 1, m) {
			int u, v2, w;
			cin >> u >> v2 >> w;
			edge q;
			q.u = u, q.v = v2, q.w = w;
			tmp[i] = q;
		}
		stable_sort(tmp + 1, tmp + m + 1);
		ll Max = 0;
		int cnt2 = n;
		E(i, 1, n) f[i] = i;
		E(i, 1, m) {
			if(cnt2 == 1) continue;
			if(gf(tmp[i].u) == gf(tmp[i].v)) continue;
			link(tmp[i].u, tmp[i].v);
			--cnt2;
			e2[++ v] = tmp[i];
			Max = max(Max, tmp[i].w);
		}
		E(i, 1, k) {
			cin >> c[i];
			E(j, 1, n) cin >> a[i][j], g[i].emplace_back(make_pair(a[i][j], j));
			stable_sort(g[i].begin(), g[i].end());
		}
		E(I, 0, (1 << k) - 1) {
			ll ret = 0, nd = 0;
			E(j, 0, n - 1) bit[j + 1] = ((I >> j) & 1), nd += bit[j + 1];
			E(i, 1, k) ret += c[i]*(ll)bit[i];
			int M = 0, cnt = n + nd;
			E(i, 1, v) e[++ M] = e2[i];
			if(n > 1e3 && k > 5){
				E(i, 1, k) {
					if(!bit[i]) continue;
					E(j, 0, 100) {
						edge q;
						q.u = n + i;
						q.v = g[i][j].second;
						q.w = g[i][j].first;
						e[++ M] = q;
					}
				}
			} else {
				E(i, 1, k) {
					if(!bit[i]) continue;
					E(j, 1, n) {
						if(a[i][j] > Max) continue;
						edge q;
						q.u = n + i;
						q.v = j;
						q.w = a[i][j];
						e[++ M] = q;
					}
				}
			}
			stable_sort(e + 1, e + M + 1);
			E(i, 1, cnt) f[i] = i;
			E(i, 1, M) {
				if(cnt == 1) break;
				if(gf(e[i].u) == gf(e[i].v)) continue;
				-- cnt;
				link(e[i].u, e[i].v);
				ret += e[i].w;
			}
			ans = min(ans, ret);
		}
		return cout << ans << "\n", void();
	}
}
int main() {
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tt = 1;
	while(tt --) wangcy::Main();
	return 0;
}
// freopen 
// IOS SYNC WITH STDIO
// CLEAR CASES
// long long

// Ex : 100pts.