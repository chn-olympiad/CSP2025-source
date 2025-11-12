#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define pli pair<ll, int> 
#define fi first
#define se second
const int N = 1e4+30;
const int M = 2.5e6+10;
struct E {
	int from;
	int to;
	int w;
	int nxt = -1;
	bool operator >(const E&B) const {
		return w > B.w;
	}
};
E eg[M];
int head[N];
ll a[13][N];//ll
ll c[13];//ll
int fa[N];
int n, m, k;
int cnt;
int s;//jian she xiang cun shu
int flagg[13];
ll minn[13];
void add(int u, int v, int w) {
	eg[++cnt].from = u;
	eg[cnt].to = v;
	eg[cnt].w = w;
	eg[cnt].nxt = head[u];
	head[u] = cnt;
}

int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

ll Kru() {
	rep(i, 1, n+s) fa[i] = i;
	priority_queue <E, vector<E>, greater<E> > pq;
	rep(i, 1, cnt) pq.push(eg[i]);
	int t = 0;
	ll ans = 0;
	while (t < n+s-1) {
		E x = pq.top();
		pq.pop();
		int u = x.from;
		int v = x.to;
		int w = x.w;
		int p = find(u);
		int q = find(v);
		if (p == q) continue;
		fa[p] = q;
		t ++;
		ans += w;
//		if (u > n) {
//			flagg[u-n] ++;
//			minn[u-n] = min(minn[u-n], w);
//		}
//		if (v > n) {
//			flagg[v-n] ++;
//			minn[v-n] = min(minn[v-n], w);
//		}
	}
	return ans;
}

bool g(int i, int j) {
	if (i&(1<<(j-1))) return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, 1, n+k) head[i] = -1;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	bool flag = 1;
	rep(i, 1, k) {
		cin >> c[i];
		if (c[i]) flag = 0;
		rep(j, 1, n) cin >> a[i][j];
	}
	if (flag) {
		rep(i, 1, k) {
			rep(j, 1, n) {
				add(n+i, j, a[i][j]);
				add(j, n+i, a[i][j]);
			}
		}
//		rep(i, 1, k) minn[k] = 1e16;
		s = k;
		ll x = Kru();
//		rep(i, 1, k) {
//			if (flagg[i] == 1) {
//				x -= minn[i];
//			}
//		}
		cout << x << '\n';
		return 0;
	}
	int t = 1<<k;
	ll ans = 1e16;
	rep(i, 0, t-1) {
		ll y = 0;
		cnt = 2*m;
		s = 0;
		rep(j, 1, k) {
			if (g(i, j)) {
				y += c[j];
				s ++;
				rep(x, 1, n) {
					add(n+j, x, a[j][x]);
					add(x, n+j, a[j][x]);
				}
			}
		}
		ll x = Kru();
		ans = min(ans, x+y);
		cout << x+y << '\n';
	}
	cout << ans << '\n';
	return 0;
}
