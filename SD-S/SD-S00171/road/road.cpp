#include <bits/stdc++.h>

using namespace std;

inline int rd() {
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-')	
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar(); 
	}
	return x * w;
}

int n, m, k;

using ll = long long;

ll a[15][10005], co[15];

namespace sub1 {
	struct node {
		int fr, to;
		ll val;
	} e[11000005];
	
	int fa[10005];
	
	int get(int x) {
		if (x == fa[x])	
			return x;
		return fa[x] = get(fa[x]);
	}
	
	bool cmp(node x, node y) {
		return x.val < y.val;
	}
	
	void sol1() {
		int cnt = m;
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int p = j + 1; p <= n; ++p)
					e[++cnt] = (node){j, p, co[i] + a[i][j] + a[i][p]};
			}
		}
		sort(e + 1, e + cnt + 1, cmp);
		ll ans = 0;
		int sum = 0;
		for (int i = 1; i <= cnt; ++i) {
			if (sum == n - 1)
				break;
			int fx = get(e[i].fr), fy = get(e[i].to);
			if (fx != fy) {
				fa[fx] = fy;
				ans += e[i].val;
				++sum;
			}
		}
		printf("%lld\n", ans);
		return;
	}
	
	bool check() {
		for (int i = 1; i <= k; ++i)
			if (co[i] != 0)	
				return 0;
		return 1;
	}
	
	node e2[15][1000005];
	
	int pt[15], vis[15], tot = 0;
	
	ll getval(int u, int i) {
		if (!vis[u])	
			return co[u] + e2[u][i].val;
		return e2[u][i].val; 
	}
	
	void sol2() {
		for (int i = 1; i <= k; ++i) {
			pt[i] = 1;
			vis[i] = 0;
		}
		pt[0] = 1;
		sort(e + 1, e + m + 1, cmp);
		for (int i = 1; i <= k; ++i) {
			tot = 0;
			for (int j = 1; j <= n; ++j)
				for (int p = j + 1; p <= n; ++p)
					e2[i][++tot] = (node){j, p, a[i][j] + a[i][p]};
		}
		for (int i = 1; i <= k; ++i)
			sort(e2[i] + 1, e2[i] + tot + 1, cmp);
		int sum = 0;
		ll ans = 0;
		while (1) {
			if (sum == n - 1)
				break;
			ll res = e[pt[0]].val;
			int id = 0;
			for (int i = 1; i <= k; ++i) {
				if (res >= getval(i, pt[i])) {
					res = getval(i, pt[i]);
					id = i;
				}
			}
			int fx, fy;
			if (!id) {
				fx = get(e[pt[0]].fr), fy = get(e[pt[0]].to);
				if (fx != fy) {
					fa[fx] = fy;
					++sum;
					ans += e[pt[0]].val;
				}
				++pt[0];
			}
			else {
				fx = get(e2[id][pt[id]].fr), fy = get(e2[id][pt[id]].to);
				if (fx != fy) {
					fa[fx] = fy;
					++sum;
					ans += res;
					if (!vis[id])	
						vis[id] = 1;
				}
				++pt[id];
			}
		}
		printf("%lld\n", ans);
		return;
	}
	
	void sol() {
		for (int i = 1; i <= n; ++i)	
			fa[i] = i;
		for (int i = 1; i <= m; ++i) {
			int a, b, c;
			a = rd(), b = rd(), c = rd();
			e[i] = (node){a, b, c};
		}
		for (int i = 1; i <= k; ++i) {
			scanf("%lld", &co[i]);
			for (int j = 1; j <= n; ++j)
				scanf("%lld", &a[i][j]);
		}
		if (check())	
			sol1();
		else
			sol2();
		return;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = rd(), m = rd(), k = rd();
	sub1 :: sol();
	return 0;
}

