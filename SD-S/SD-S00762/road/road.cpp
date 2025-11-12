#include <iostream>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <ctime>
using namespace std;
const int N = 1e4 + 100, M = 1e6 + 10;
using ll = long long;
struct DSU {
	int fa[N];
	inline void Init(int n) {
		iota(fa + 1, fa + n + 1, 1);
	}
	inline int Find(int x) {
		if (x == fa[x]) return x;
		return fa[x] = Find(fa[x]);
	}
	inline bool Merge(int u, int v) {
		int x = Find(u), y = Find(v);
		if (x == y) return false;
		return fa[x] = y, true;
	}
} dsu;
struct Edge {
	int u, v, w;
	bool operator<(const Edge &x) const {
		return w < x.w;
	}
} ke[1025][N << 1], beg[M];
ll a[20][N], c[20], reg[1025];
inline int lowbit(int x) {
	return x & -x;
}
inline ll Kruskal(int n, int m, Edge *eg, Edge *wr) {
	sort(eg + 1, eg + m + 1);
	int cnt = 0;
	ll sum = 0;
	dsu.Init(n + 10);
	for (int i = 1; i <= m; i++) {
		int u = eg[i].u, v = eg[i].v, w = eg[i].w;
		if (dsu.Merge(u, v)) wr[++cnt] = eg[i], sum += w;
		if (cnt == n - 1) break;
	}
	return sum;
}
int main() {
	ifstream fin("road.in");
	ofstream fout("road.out");
	#define cin fin
	#define cout fout
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		beg[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	ll ans = Kruskal(n, m, beg, ke[0]);
	for (int i = 1; i < (1 << k); i++) {
		int add = __lg(lowbit(i)) + 1, bef = i - lowbit(i);
		reg[i] = reg[bef] + c[add];
		int nn = n + __builtin_popcount(i);
		memcpy(ke[i], ke[bef], sizeof(Edge) * nn);
		for (int j = 1; j <= n; j++) ke[i][nn + j - 1] = {n + add, j, a[add][j]};
		ll ret = Kruskal(nn, nn + n - 1, ke[i], ke[i]);
		ans = min(ans, ret + reg[i]);
	}
	cout << ans << endl;
}
