#include <bits/stdc++.h>
#define i32 int
#define i64 long long
#define For(i, l, r) for (i32 i = (l); i <= (r); i++)
using namespace std;


const i32 N = 1e4 + 5;
const i32 M = 1e6 + 5;
const i32 K = 15;

struct Edge { i32 w, u, v; };
vector < Edge > E;
i32 n, m, k, id[K];
i64 ans, now = 0;
i32 fa[N], ee[K][N], cost[K];
i32 find(i32 x) { return (x == fa[x]) ? (x) : (fa[x] = find(fa[x])); }
inline void merge(i32 x, i32 y) {
	x = find(x), y = find(y);
	fa[x] = y;
}
struct Tree {
	vector < Edge > e;
};
Tree org;
Tree P[K];
inline Tree operator + (const Tree& a, const Tree& b) {
	Tree res;
	iota(fa + 1, fa + 1 + n, 1);
	Edge e;
	// cerr << a.e.size() << ' ' << b.e.size() << endl;
	for (i32 i = 0, j = 0; i < n - 1 || j < n - 1;) {
		if (i == n - 1 || b.e[j].w < a.e[i].w) e = b.e[j++];
		else e = a.e[i++];
		if (find(e.u) != find(e.v)) {
			merge(e.u, e.v);
			res.e.emplace_back(e);
		}
	}
	return res;
}
inline i64 CalcCost(const Tree& tr) {
	i64 res = 0;
	for (auto i : tr.e) res += i.w;
	return res;
}
void dfs(i32 x, Tree tree) {
	if (x == k + 1) {
		ans = min(ans, CalcCost(tree) + now);
		return ;
	}
	dfs(x + 1, tree);
	now += cost[x];
	// cerr << x << ' ' << P[x].e.size() << endl;
	dfs(x + 1, tree + P[x]);
	now -= cost[x];
}
// mt19937 rnd(time(0));
// inline i32 rand(i32 l, i32 r) { return rnd() % (r - l + 1) + l; }
inline void ___() {
	cin >> n >> m >> k;
	// n = 1e4, m = 1e6, k = 10;
	iota(fa + 1, fa + 1 + n, 1);
	For (i, 1, m) {
		i32 u, v, w;
		cin >> u >> v >> w;
		// u = rand(1, n), v = rand(1, n), w = rand(0, 1e9);
		E.push_back({ w, u, v });
	}
	// cerr << "???" << endl;
	For (i, 1, k) {
		// cerr << i << endl;
		id[i] = 1;
		For (j, 0, n) {
			cin >> ee[i][j];
			// ee[i][j] = rand(0, 1e9);
			if (j > 0 && ee[i][j] < ee[i][id[i]]) id[i] = j;
		}
		ee[i][0] += ee[i][id[i]];
		ee[i][id[i]] = 0;
		For (j, 1, n) {
			if (j != id[i]) P[i].e.push_back({ ee[i][j], id[i], j });
		}
		sort(P[i].e.begin(), P[i].e.end(), [&](Edge a, Edge b) { return a.w < b.w; });
		// For (j, 0, n - 2) cerr << P[i].e[j].u << ' ' << P[i].e[j].v << '\n';
		cost[i] = ee[i][0];
		// For (j, 0, n) cerr << ee[i][j] << " \n"[j == n];
	}
	sort(E.begin(), E.end(), [&](Edge a, Edge b) { return a.w > b.w; });
	for (i32 i = (E.size() * 1ll - 1ll); i >= 0; i--) {
		Edge e = E[i];
		if (find(e.u) != find(e.v)) {
			merge(e.u, e.v);
			now += e.w;
			org.e.push_back(e);
		}
	}
	// cerr << now << endl;
	ans = now;
	now = 0;
	dfs(1, org);
	// cout << ans << '\n';
	// dfs(1);
	cout << ans << '\n';
}



signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	double be = clock();
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	i32 T = 1; //cin >> T;
	while (T--) ___();
	// cerr << "times: " << (clock() - be) * 1.0 / CLOCKS_PER_SEC << endl;
}