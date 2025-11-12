// SN-S00691
// E: 60
#include <bits/stdc++.h>
using namespace std;
template<typename T> void fast_read(T &x) {
	T f = 1;
	x = 0;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}
template<typename T> void fast_write(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) fast_write(x / 10);
	putchar(x % 10 + '0');
}
const int MAXN = 5e5 + 10;
struct Edge {
	int u, v, w;
};
vector<Edge> G;
int n, m, k, ans, tot;
int fa[MAXN];
void add(int u, int v, int w) {
	G.push_back((Edge){u, v, w});
	tot++;
}
int num(int x, int _k) {
	return x + n + _k * k;
}
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
int query(int x) {
	if (x == fa[x]) return x;
	return fa[x] = query(fa[x]);
}
void kruskal() {
	for (int i = 1; i <= num(k, 1) + 1; i++) fa[i] = i;
	sort(G.begin(), G.end(), cmp);
	for (int i = 0; i < tot; i++) {
		int x = query(G[i].u), y = query(G[i].v), w = G[i].w;
		if (x == y) continue;
		fa[x] = y;
		ans += w;
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fast_read(n), fast_read(m), fast_read(k);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		fast_read(u), fast_read(v), fast_read(w);
		add(u, v, w);
	}
	for (int i = 1; i <= k; i++) {
		int x;
		fast_read(x);
		add(num(i, 0), num(i, 1), x);
		for (int j = 1; j <= n; j++) {
			fast_read(x);
			add(num(i, 1), j, x);
		}
	}
	kruskal();
	fast_write(ans);
	return 0;
}
