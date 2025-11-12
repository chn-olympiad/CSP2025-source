#include <bits/stdc++.h>
using namespace std;
struct IO {
	IO() {
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
	}
	~IO() {
		fclose(stdin);
		fclose(stdout);
	}
};
IO io;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, K, eC;
struct Edge {
	int u, v, w;
	Edge() { u = v = w = 0; }
	Edge(int _u, int _v, int _w) { u = _u, v = _v, w = _w; }
} edg[M], e[N + 10 * N];
int fa[N], c[N];
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
ll Work(int S) {
	int cnt = n;
	ll wei = 0;
	for (int i = 0; i < K; i++)
		if (S >> i & 1)
			cnt++, wei += c[i + 1];
	for (int i = 1; i <= n + K; i++) fa[i] = i;
	for (int i = 1; i <= eC; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (Find(u) == Find(v)) continue;
		if (u <= n || (S >> (u - n - 1) & 1)) {
			fa[Find(u)] = Find(v);
			cnt--;
			wei += w;
		}
	}
	return wei;
}
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1, u, v, w; i <= m; i++)
		scanf("%d%d%d", &edg[i].u, &edg[i].v, &edg[i].w);
	sort(edg + 1, edg + m + 1, [](const Edge &a, const Edge &b) { return a.w < b.w; });
	ll wei = 0;
	int cntcc = n;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int u = edg[i].u, v = edg[i].v, w = edg[i].w;
		if (Find(u) != Find(v)) {
			wei += w;
			fa[Find(u)] = Find(v);
			e[++eC] = edg[i];
			cntcc--;
		}
	}
	ll ans = 1e18;
	if (cntcc == 1) ans = wei;
	for (int i = 1; i <= K; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			eC++, scanf("%d", &e[eC].w), e[eC].u = n + i, e[eC].v = j;
	}
	sort(e + 1, e + eC + 1, [](const Edge &a, const Edge &b) { return a.w < b.w; });
	for (int i = 1; i < (1 << K); i++) {
		ans = min(ans, Work(i));
	}
	printf("%lld\n", ans);
	return 0;
}