#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 20, M = 2e6 + 10;
using ll = long long;

bool Mbe;
int n, m, k;
struct Edge {
	int u, v, w;
	bool operator < (const Edge& t) const {
		return w < t.w;
	}
} e1[M], e2[M];
int w[11][N];
int p[N], sz[N];
ll res = 1e18;

inline void rd(int &x) {
	x = 0; char ch = getchar();
	while (ch < 48 || ch > 57) ch = getchar();
	while (ch >= 48 && ch <= 57) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
}

int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(vector<int> cur) {
	int K = m + (int)cur.size() * n; int tot = 0; ll ans = 0;
	for (int i = 1; i <= m; i ++ ) e2[ ++ tot] = e1[i];
	for (int p = 0; p < (int)cur.size(); p ++ ) {
		ans += w[cur[p]][0];
		for (int i = 1; i <= n; i ++ ) e2[ ++ tot] = {i, n + p + 1, w[cur[p]][i]};
	}
	sort(e2 + 1, e2 + 1 + tot);
	int cnt = n + (int)cur.size();
	for (int i = 1; i <= n + (int)cur.size(); i ++ ) ::p[i] = i, sz[i] = 1;
	for (int i = 1; i <= K; i ++ ) {
		int u = e2[i].u, v = e2[i].v, w = e2[i].w;
		int pa = find(u), pb = find(v);
		if (pa == pb) continue ;
		ans += w; if (sz[pa] < sz[pb]) swap(pa, pb);
		::p[pb] = pa, sz[pa] += sz[pb]; cnt -- ;
		if (cnt == 1) break ;
	} res = min(res, ans);
}

bool Med;
int main() {
	cerr << (&Mbe - &Med) / 1048576.0 << '\n';
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> m >> k; bool flg = 1;
	for (int i = 1; i <= m; i ++ ) {
		cin >> e1[i].u >> e1[i].v >> e1[i].w;
	} sort(e1 + 1, e1 + 1 + m); int tot = 0;
	for (int i = 1; i <= n; i ++ ) p[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; i ++ ) {
		int pa = find(e1[i].u), pb = find(e1[i].v);
		if (pa != pb) {
			p[pa] = pb;
			e2[ ++ tot] = e1[i];
		}
	}
	for (int i = 1; i < n; i ++ ) e1[i] = e2[i]; m = n - 1;
	for (int i = 1; i <= k; i ++ ) {
		for (int j = 0; j <= n; j ++ ) cin >> w[i][j];
		flg &= (!w[i][0]);
	}
	for (int S = 0; S < 1 << k; S ++ ) {
		vector<int> cur;
		for (int i = 0; i < k; i ++ ) if (S >> i & 1) cur.push_back(i + 1);
		solve(cur);
	}
	cout << res << '\n'; return 0;
}
