#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> PII;
typedef tuple<int, int, int> Edge; 

#define ep emplace
#define eb emplace_back
#define fir first
#define sec second

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}

const int K = 15, N = 20010, M = 2000010;

int n, m, k, tot, ans = 1e18;
int p[N], sz[N], a[K][N], w[M];
vector<Edge> e;
bool del[M];

int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

bool cmp(Edge &a, Edge &b) {
	int ia = get<2>(a), ib = get<2>(b);
	return w[ia] < w[ib];
}

void merge(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa == pb) return;
	if (sz[pa] > sz[pb]) swap(pa, pb);
	sz[pb] += sz[pa], p[pa] = pb;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	bool flag = true;
	for (int i = 1; i <= m; i ++ ) {
		int a = read(), b = read(), c = read();
		w[ ++ tot] = c, e.eb(a, b, tot);
	}
	for (int i = 1; i <= k; i ++ ) {
		w[ ++ tot] = read(), a[i][0] = tot;
		if (w[tot]) flag = false;
		e.eb(n + 2 * i - 1, n + 2 * i, tot);
		for (int j = 1; j <= n; j ++ ) {
			w[ ++ tot] = read(), a[i][j] = tot;
			e.eb(n + 2 * i, j, tot);
		}
	}
	sort(e.begin(), e.end(), cmp);
	if (flag && k > 5) {
		for (int i = 1; i <= n + 2 * k; i ++ ) p[i] = i, sz[i] = 1;
		int res = 0;
		for (auto &edge : e) {
			int a, b, id; tie(a, b, id) = edge;
			if (del[id]) continue;
			if (find(a) == find(b)) continue;
			merge(a, b), res += w[id];
		}
		ans = min(ans, res);
	}
	else {
		int sto = (1 << k) - 1;
		for (int s = 0; s <= sto; s ++ ) {
			for (int i = 1; i <= k; i ++ ) {
				if (s >> (i - 1) & 1) for (int j = 0; j <= n; j ++ ) del[a[i][j]] = false;
				else for (int j = 0; j <= n; j ++ ) del[a[i][j]] = true;
			}
			for (int i = 1; i <= n + 2 * k; i ++ ) p[i] = i, sz[i] = 1;
			int res = 0;
			for (auto &edge : e) {
				int a, b, id; tie(a, b, id) = edge;
				if (del[id]) continue;
				if (find(a) == find(b)) continue;
				merge(a, b), res += w[id];
			}
			ans = min(ans, res);
		}
	}
	printf("%lld\n", ans); 
	return 0;
}
/*
如果要对一个乡镇进行改造，则其一定与其他 n 个点联通，否则改造是无用的 
相当于将乡镇拆成两个点做最小生成树。 
容易做到 O((m+kn)logm+(m+kn)*2^k*alpha)，64pts 
特殊性质 A: 直接做最小生成树。
3:48 finish 72。
*/
