#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k, fa[N], head[N << 1], nxt[N << 1], to[N << 1], idx;
vector<int> g1, g2;
struct node1 {
	int u, v, w, f;
} e[M];
struct node2 {
	int c, f1, f2[N], a[N];
} d[20];
bool cmp1 (node1 a, node1 b) {
	return a.w < b.w;
}
bool cmp2 (node1 a, node1 b) {
	return a.w > b.w;
}
void add (int u, int v) {
	to[++idx] = v;
	nxt[idx] = head[u];
	head[u] = idx;
}
int find (int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int kruscal () {
	long long res = 0, cnt = 0;
	sort(e + 1, e + m + 1, cmp1);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int x = find(u), y = find(v);
		if (x == y)
			continue;
		fa[x] = y, res += w, e[i].f = 1;
	}
	return res;
}
void dfs1 (int u, int f) {
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == f)
			continue;
		g1.push_back(v);
		dfs1(v, u);
	}
}
void dfs2 (int u, int f) {
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == f)
			continue;
		g2.push_back(v);
		dfs2(v, u);
	}
}
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; ++i) {
		cin >> d[i].c, d[i].f1 = 1;
		for (int j = 1; j <= n; ++j)
			cin >> d[i].a[j], d[i].f2[j] = 1;
		sort(d[i].a + 1, d[i].a + n + 1);
	}
	long long ans = kruscal();
	if (!k) {
		cout << ans;
		return 0;
	}
	sort(e + 1, e + n, cmp2);
	for (int i = 1; i < n; ++i) {
		memset(head, 0, sizeof(head));
		idx = 0, g1.clear(), g2.clear();
		for (int j = 1; j < n; ++j)	{
			if (i == j)
				continue;
			add(e[j].u, e[j].v);
			add(e[j].v, e[j].u);
		}
		dfs1(e[i].u, 0), dfs2(e[i].v, 0);
		int u = e[i].u, v = e[i].v, p, p1, p2;
		long long minx = 3e9 + 1;
		for (int j = 1; j <= k; ++j) {
			long long c = d[j].c * d[j].f1, q1, q2, minn = 3e9 + 1;
			for (int l = 0; l < g1.size(); ++l) {
				int t = g1[l];
				if (d[j].f2[t] * d[j].a[t] < minn)
					minn = d[j].f2[t] * d[j].a[t], q1 = t;
			}
			minn = 3e9 + 1;
			for (int l = 0; l < g2.size(); ++l) {
				int t = g2[l];
				if (d[j].f2[t] * d[j].a[t] < minn)
					minn = d[j].f2[t] * d[j].a[t], q2 = t;
			}
			if (c + minn < minx)
				minx = c + minn, p = j, p1 = q1, p2 = q2;
		}
		if (minx >= e[i].w)
			continue;
		ans += minx, ans -= e[i].w;
		d[p].f1 = d[p].f2[p1] = d[p].f2[p2] = 0;
	}
	cout << ans;
	return 0;
} 
