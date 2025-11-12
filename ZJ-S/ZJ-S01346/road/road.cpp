#include <bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define uint unsigned int
using namespace std;

namespace ROAD {

const int N = 1e4 + 50;
const int M = 1e6 + 50;
struct Edge { int u, v, w; } e[M], A[12][N], cur[1050][N], tmp[N * 2];
int n, m, K, C[N], len[1050];

int fa[N]; int Find(int u) { return (fa[u] == u ? u : fa[u] = Find(fa[u])); }

void merge(Edge* a, Edge* b, Edge* c, int n, int m) {
	int p = 1, q = 1, len = 0;
	for (; p <= n && q <= m; ) {
		if (a[p].w < b[q].w) c[++ len] = a[p ++];
		else c[++ len] = b[q ++];
	}
	for (; p <= n; p ++) c[++ len] = a[p];
	for (; q <= m; q ++) c[++ len] = b[q];
	return ;
}

void main() {
	cin >> n >> m >> K;
	for (int i = 1, u, v, w; i <= m; i ++)
		cin >> u >> v >> w, e[i] = {u, v, w};
	sort(e + 1, e + 1 + m, [](Edge a, Edge b) { return a.w < b.w; });
	for (int i = 0; i < K; i ++) {
		cin >> C[i];
		for (int j = 1, w; j <= n; j ++) cin >> w, A[i][j] = {n + i + 1, j, w};
		sort(A[i] + 1, A[i] + 1 + n, [](Edge a, Edge b) { return a.w < b.w; });
	}
	LL Ans = 1e18, sum = 0; 
	for (int i = 1; i <= n; i ++) fa[i] = i;
	for (int i = 1; i <= m; i ++) {
		int u = Find(e[i].u), v = Find(e[i].v);
		if (u != v) fa[u] = v, sum += e[i].w, cur[0][++ len[0]] = e[i];
		if (len[0] == n - 1) break;
	}
	Ans = sum;
	for (int s = 1; s < (1 << K); s ++) {
		LL res = 0; int p = 0, ptot = n;
		for (int i = 0; i < K; i ++) if ((s >> i) & 1) p = i, res += C[i], ++ ptot;
		merge(cur[s ^ (1 << p)], A[p], tmp, len[s ^ (1 << p)], n);
		for (int i = 1; i <= n + K; i ++) fa[i] = i;
		for (int i = 1; i <= len[s ^ (1 << p)] + n; i ++) {
			int u = Find(tmp[i].u), v = Find(tmp[i].v);
			if (u != v) res += tmp[i].w, cur[s][++ len[s]] = tmp[i], fa[u] = v;
			if (len[s] == ptot - 1) break;
		}
		Ans = min(Ans, res);
	}
	cout << Ans << "\n"; return ;
}

}

int main() {
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ROAD::main();
	return 0;
}