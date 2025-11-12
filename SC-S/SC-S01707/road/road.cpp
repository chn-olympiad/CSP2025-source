#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IO {
	IO() { freopen("road.in", "r", stdin), freopen("road.out", "w", stdout); }
	~IO() { fclose(stdin), fclose(stdout); }
} io;
int n, m, k;
struct EDat {
	int u, v; ll w;
	bool operator<(const EDat &b) const {
		return w < b.w;
	}
} ed[1000005], ek[15][10005];
ll c[15], a[15][10005];
int eC;
int fa[11005];
int F(int u) { return fa[u] == u ? u : fa[u] = F(fa[u]); }
EDat st[30005];
int sC;
ll ans = 1e18;
int GetMST(EDat *e, int c) {
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	int p = 0;
	for (int i = 1; i <= c; i++) {
		auto x = e[i];
		int u = x.u, v = x.v; ll w = x.w;
		if (F(u) != F(v)) {
			fa[F(u)] = F(v);
			e[++p] = { u, v, w };
		}
	}
	return p;
}
void Solve(int s, int p) {
	if (p == k) {
		ll w = 0;
		for (int i = 0; i < k; i++) if (s >> i & 1) w += c[i + 1];
		for (int i = 1; i <= sC; i++) w += st[i].w;
		ans = min(ans, w);
		return;
	}
	Solve(s, p + 1);
	EDat tSt[11005];
	int tC = sC;
	for (int i = 1; i <= sC; i++) tSt[i] = st[i];
	for (int i = 1; i <= n; i++) st[++sC] = ek[p + 1][i];
	inplace_merge(st + 1, st + tC + 1, st + sC + 1);
	sC = GetMST(st, sC);
	Solve(s | (1 << p), p + 1);
	sC = tC;
	for (int i = 1; i <= sC; i++) st[i] = tSt[i];
}
template <class T>
void read(T &x) {
	char c;
	while (!isdigit(c = getchar()));
	x = c ^ 48;
	while (isdigit(c = getchar())) x = x * 10 + (c ^ 48);
}
int main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= m; i++) {
		int u, v; ll w; 
		read(u), read(v), read(w);
		ed[i] = { u, v, w };
	}
	for (int i = 1; i <= k; i++) {
		read(c[i]);
		for (int j = 1; j <= n; j++) {
			read(a[i][j]);
			ek[i][j] = { i + n, j, a[i][j] };
		}
		sort(ek[i] + 1, ek[i] + n + 1);
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(ed + 1, ed + m + 1);
	for (int i = 1; i <= m; i++) {
		int u = ed[i].u, v = ed[i].v; ll w = ed[i].w;
		if (F(u) != F(v)) {
			fa[F(u)] = F(v);
			st[++sC] = { u, v, w };
		}
	}
	Solve(0, 0);
	printf("%lld\n", ans);
	return 0;
}
// 14:55