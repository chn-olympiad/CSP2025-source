#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define L(i, l, r, a) for(int i = l; i <= r; i += a)
#define R(i, l, r, a) for(int i = r; i >= l; i -= a)
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define N 10010
using namespace std;
const int inf = 1e18;
int read() {
	int f = 1, x = 0;
	char c = getchar();
	while(!isdigit(c)) {if(c == '-') f = -1;c = getchar();}
	while(isdigit(c)) {x = x * 10 + c - '0';c = getchar();}
	return f * x;
}
int n, m, k;
struct EDGE {
	int u, v, w;
}e[N * 100], ee[N];
int c[N];
pii a[11][N];
struct bcj {
	int fa[N];
	void init() {
		L(i, 1, n, 1) fa[i] = i;
	}
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	void merge(int x, int y) {
		fa[find(x)] = find(y);
	}
}b;
int ans, res;
void kruskal() {
	sort(e + 1, e + m + 1, [](EDGE e1, EDGE e2){return e1.w < e2.w;});
	b.init();
	int cnt = 0;
	L(i, 1, m, 1) {
		int x = b.find(e[i].u), y = b.find(e[i].v);
		if(x != y) {
			ee[++cnt] = e[i];
			ans += e[i].w;
			b.merge(x, y);
		}
	}
}
bool is[11];
int it[12];
void func() {
	b.init();
	int cnt = 1, id = 0;
	res = 0;
	L(i, 0, k, 1) it[i] = 1;
	while(cnt < n) {
		EDGE e = {0, 0, inf};
		while(it[0] < n) {
			if(b.find(ee[it[0]].u) != b.find(ee[it[0]].v)) {
				if(e.w > ee[it[0]].w) {
					e = ee[it[0]];
					id = 0;
				}
				break;
			}
			it[0]++;
		}
		L(i, 1, k, 1) {
			if(!is[i]) continue;
			while(it[i] <= n) {
				if(b.find(a[i][1].se) != b.find(a[i][it[i]].se)) {
					if(e.w > a[i][it[i]].fi) {
						e = {a[i][1].se, a[i][it[i]].se, a[i][it[i]].fi};
						id = i;
					}
					break;
				}
				it[i]++;
			}
		}
		int x = b.find(e.u), y = b.find(e.v);
		b.merge(x, y);
		res += e.w;
		it[id]++;
		cnt++;
	}
}
void brute(int u, int sum) {
	if(u == k + 1) {
		func();
		ans = min(ans, res + sum);
		return;
	}
	brute(u + 1, sum);
	is[u] = 1;
	brute(u + 1, sum + c[u] + a[u][1].fi);
	is[u] = 0;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();m = read();k = read();
	L(i, 1, m, 1) {
		e[i].u = read();e[i].v = read();e[i].w = read();
	}
	kruskal();
	L(i, 1, k, 1) {
		cin >> c[i];
		L(j, 1, n, 1) {
			cin >> a[i][j].fi;
			a[i][j].se = j;
		}
		sort(a[i] + 1, a[i] + n + 1);
	}
	brute(1, 0);
	cout << ans;
	return 0;
}