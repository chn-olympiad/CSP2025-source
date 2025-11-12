#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 5;
const ll inf = 1e17;
using pr = pair<ll, ll>;
ll n, m, k, dis[N], sz[N], a[N][15], c[15], ans, fa[N], to[15];
int query(int x) {
	return x == fa[x] ? x : fa[x] = query(fa[x]);
}
struct ed {
	ll u, v, w;
}e[2000005];
bool vis[N];
vector<ed> g[N];
priority_queue<pr, vector<pr>, greater<pr> > q;
bool check() {
	bool flag = true;
	for(int i = 1;i <= k;i++) {
		if(c[i] != 0) flag = false;
	}
	return flag;
}
ll read() {
	ll x = 0; char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9' && ch >= '0') {
		x = x * 10 + (ch - '0'); ch = getchar();
	}
	return x;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	for(int i = 1;i <= m;i++) {
		e[i].u = read(); e[i].v = read(); e[i].w = read();
		g[e[i].u].push_back({e[i].v, e[i].w});
		g[e[i].v].push_back({e[i].u, e[i].w});
	}
	for(int j = 1;j <= k;j++) {
		c[j] = read();
		for(int i = 1;i <= n;i++) a[i][j] = read();
	}
	if(k == 0) {
		for(int i = 1;i <= n;i++) fa[i] = i;
		sort(e + 1, e + m + 1, [](ed x, ed y) {
			return x.w < y.w;
		});
		for(int i = 1;i <= m;i++) {
			ll qx = query(e[i].u), qy = query(e[i].v);
			if(qx != qy) {
				fa[qx] = qy; ans += e[i].w;
			}
		}
		printf("%lld\n", ans);
	} else if(check()) {
		for(int j = 1;j <= k;j++) {
			for(int i = 1;i <= n;i++) {
				if(a[i][j] == 0) {
					to[j] = i; break;
				}
			}
		}
		for(int j = 1;j <= k;j++) {
			for(int i = 1;i <= n;i++) {
				if(i != to[j]) e[++m] = {to[j], i, a[i][j]};
			}
		}
		for(int i = 1;i <= n;i++) fa[i] = i;
		sort(e + 1, e + m + 1, [](ed x, ed y) {
			return x.w < y.w;
		});
		for(int i = 1;i <= m;i++) {
			ll qx = query(e[i].u), qy = query(e[i].v);
			if(qx != qy) {
				fa[qx] = qy; ans += e[i].w;
			}
		}
		printf("%lld\n", ans);
	} else {
		for(int i = 1;i <= n;i++) fa[i] = i;
		sort(e + 1, e + m + 1, [](ed x, ed y) {
			return x.w < y.w;
		});
		for(int i = 1;i <= m;i++) {
			ll qx = query(e[i].u), qy = query(e[i].v);
			if(qx != qy) {
				fa[qx] = qy; ans += e[i].w;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
