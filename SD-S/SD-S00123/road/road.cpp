#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 10020;
const int M = 1000010;

int n, m, k, cnt;
int fa[N], vis[N], add;
struct Edge {
	int u, v;
	LL w;
} a[M], b[M], c[M];
LL w[20], t[20][N];
vector<int> use[20];
LL ans = 1e18, fir;

bool mycmp(Edge x, Edge y) {
	return x.w < y.w;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void build() {
	for(int i = 1; i <= n; ++ i) fa[i] = i;
	int cur = 0;
	for(int i = 1; i <= m; ++ i) {
		int x = find(a[i].u), y = find(a[i].v);
		if(x == y) continue;
		b[++ cnt] = a[i]; fir += a[i].w;
		fa[x] = y; ++ cur;
		if(cur == n - 1) break;
	}
}

void Kruskal(int tot, LL &res) {
	for(int i = 1; i <= n + k; ++ i) fa[i] = i;
	int cur = 0, l = 1, r = 1;
	while(l < n && r <= add) {
		if(b[l].w < c[r].w) {
			int x = find(b[l].u), y = find(b[l].v);
			++ l;
			if(x == y) continue;
			++ cur;
			fa[x] = y; res += b[l - 1].w;
		} else {
			int x = find(c[r].u), y = find(c[r].v);
			++ r;
			if(x == y) continue;
			++ cur; vis[c[r - 1].v] = 1;
			fa[x] = y; res += c[r - 1].w;
		}
		if(cur == tot - 1) break;
	}
	while(l < n) {
		int x = find(b[l].u), y = find(b[l].v);
		++ l;
		if(x == y) continue;
		++ cur;
		fa[x] = y; res += b[l - 1].w;
		if(cur == tot - 1) break;
	}
	while(r <= add) {
		int x = find(c[r].u), y = find(c[r].v);
		++ r;
		if(x == y) continue;
		++ cur; vis[c[r - 1].v] = 1;
		fa[x] = y; res += c[r - 1].w;
		if(cur == tot - 1) break;
	}
}

LL read() {
	LL x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - 48);
		ch = getchar();
	}
	return x;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	for(int i = 1; i <= m; ++ i) {
		a[i].u = read();
		a[i].v = read();
		a[i].w = read();
	}
	sort(a + 1, a + m + 1, mycmp);
	build();
	for(int i = 0; i < k; ++ i) {
		w[i] = read(); add = 0;
		for(int j = 1; j <= n; ++ j) {
			t[i][j] = read();
			vis[j] = 0;
			c[++ add] = {n + i + 1, j, t[i][j]};
		}
		sort(c + 1, c + add + 1, mycmp);
		LL tt = w[i];
		Kruskal(n + 1, tt);
		if(tt >= fir) {
			-- i; -- k;
		}
	}
	for(int s = 0; s < (1 << k); ++ s) {
		add = 0; int tot = 0;
		LL now = 0;
		for(int i = 0; i < k; ++ i)
			if((s >> i) & 1) {
				++ tot; now += w[i];
				for(int j = 1; j <= n; ++ j)
					c[++ add] = {n + i + 1, j, t[i][j]};
			}
		sort(c + 1, c + add + 1, mycmp);
		Kruskal(n + tot, now);
		ans = min(ans, now);
	}
	printf("%lld", ans);
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4



*/


