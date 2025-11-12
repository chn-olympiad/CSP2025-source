#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, m, k, ans, c[1005], fa[100005], cnt, b[12], siz[50];
bool flag[12];
struct node {
	int u, v, w;
}sid[1000005], a[12][10005], now[500005], now2[50][130005];
bool cmp(node x, node y) {
	return x.w < y.w;
}
void pushup(int id, int siz1, int siz2) {
	int p = 1, q = 1;
	int tmp = 0;
	while(p <= siz1 && q <= siz2) {
		if(cmp(now2[id << 1][p], now2[id << 1 | 1][q])) {
			now2[id][++tmp] = now2[id << 1][p];
			++p;
		}
		else {
			now2[id][++tmp] = now2[id << 1 | 1][q];
			++q;
		}
	}
	while(p <= siz1)	now2[id][++tmp] = now2[id << 1][p++];
	while(q <= siz2)	now2[id][++tmp] = now2[id << 1 | 1][q++];
	return;
}
inline void build(int p, int l, int r) {
	if(l == r) {
		if(l == 0) {
			for(int i = 1; i <= cnt; ++i) {
				now2[p][i] = now[i];
			}
			siz[p] = cnt;
		}
		else {
			for(int i = 1; i <= n; ++i) {
				now2[p][i] = a[b[l]][i];
			}
			siz[p] = n;
		}
		return;
	}
	int mid = l + r >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p, siz[p << 1], siz[p << 1 | 1]);
	siz[p] = siz[p << 1] + siz[p << 1 | 1];
	return;
}
void init() {
	for(int i = 1; i <= n + k; ++i) {
		fa[i] = i;
	}
	return;
}
inline int get_root(int x) {
	if(fa[x] == x)	return x;
	return fa[x] = get_root(fa[x]);
}
void solve() {
	int nowtmp = 0;
	for(int i = 1; i <= k; ++i) {
		if(flag[i]) {
			b[++nowtmp] = i;
		}
	}
	build(1, 0, nowtmp);
	return;
}
inline int work() {
	solve();
	init();
	int sum = 0;
	for(int i = 1; i <= siz[1]; ++i) {
		int u = get_root(now2[1][i].u), v = get_root(now2[1][i].v);
		if(u == v)	 continue;
		sum += now2[1][i].w;
		fa[u] = v;
	}
	return sum;
}
void dfs(int step, int val) {
	if(step == k + 1) {
		ans = min(ans, val + work());
		return;
	}
	dfs(step + 1, val);
	flag[step] = true;
	dfs(step + 1, val + c[step]);
	flag[step] = false;
	return;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	for(int i = 1; i <= m; ++i) {
		sid[i].u = read(); sid[i].v = read(); sid[i].w = read();
	}
	sort(sid + 1, sid + m + 1, cmp);
	init();
	int sum = 0;
	for(int i = 1; i <= m; ++i) {
		int u = get_root(sid[i].u), v = get_root(sid[i].v);
		if(u == v)	continue;
		fa[u] = v;
		sum += sid[i].w;
		now[++cnt] = sid[i];
	}
	ans = sum;
	for(int i = 1; i <= k; ++i) {
		c[i] = read();
		for(int j = 1; j <= n; ++j) {
			a[i][j].u = n + i;
			a[i][j].v = j;
			a[i][j].w = read();
		}
		sort(a[i] + 1, a[i] + n + 1, cmp);
	}
	dfs(1, 0);
	cout<<ans;
	return 0;
}
