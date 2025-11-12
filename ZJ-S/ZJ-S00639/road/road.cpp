#include<bits/stdc++.h>
#define ll long long
#define PII pair<int, pair<int,int> >  
using namespace std;
const int N = 1e4 + 30;
const int M = 1e6 + 10;
struct node {
	int u, v, w;
}bian[M];
vector<PII> g[N];
int u[M], v[M], w[M];
int vis[N];
int c[20], a[20][N];
int f[N];
ll tot, ans;
int n, m, k; 
priority_queue<int, vector<PII>, greater<PII> > q;
inline bool cmp (node a, node b) {
	if (a.u == b.u) {
		if (a.v == b.v) return a.w < b.w;
		return a.v < b.v;
	}
	return a.u < b.u;
}
inline int find (int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
inline void init () {
	tot = 0, ans = 0;
	for (int i = 1; i <= n + k; ++i) {
		f[i] = i;
	}
	while (!q.empty()) q.pop(); 
}
inline ll sub1() {
	init();
	for (int i = 1; i <= m; ++i) {
		if (bian[i].w == -1) continue;
		q.push({bian[i].w, {bian[i].u, bian[i].v}});
	}
	while (1) {
		if (tot == n - 1) {
			return ans;
		}
		int w = q.top().first, u = q.top().second.first, v = q.top().second.second; 
		q.pop();
		if (find(u) != find(v)) {
			f[f[u]] = f[v];
			tot ++;
			ans += w;
		}
	}
}
inline ll sub2() {
	init();
	for (int i = 1; i <= m; ++i) {
		if (bian[i].w == -1) continue;
		q.push({bian[i].w, {bian[i].u, bian[i].v}});
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			q.push({a[i][j], {i + n, j}});
		}
	}
	while (1) {
		if (tot == n + k - 1) {
			return ans;
		}
		int w = q.top().first, u = q.top().second.first, v = q.top().second.second; 
		q.pop();
		if (find(u) != find(v)) {
			f[f[u]] = f[v];
			tot ++;
			ans += w;
		}
	}
}
ll anss = 1e18;
inline void checkk () {
	init();
	for (int i = 1; i <= m; ++i) {
		if (bian[i].w == -1) continue;
		q.push({bian[i].w, {bian[i].u, bian[i].v}});
	}
	int ccnt = 0;
	for (int i = 1; i <= k; ++i) {
		if (vis[i] == 0) continue;
		ans += c[i];
		ccnt ++;
		for (int j = 1; j <= n; ++j) {
			q.push({a[i][j], {i + n, j}});
		}
	}
	while (1) {
		if (tot == n + ccnt - 1) {
			anss = min(anss, ans);
			return;
		}
		int w = q.top().first, u = q.top().second.first, v = q.top().second.second; 
		q.pop();
		if (find(u) != find(v)) {
			f[f[u]] = f[v];
			tot ++;
			ans += w;
		}
	}
}
inline void dfs (int x) {
	if (x == k + 1) {
		checkk();
		return;
	}
	dfs (x + 1);
	vis[x] = 1;
	dfs (x + 1);
	vis[x] = 0;
} 
inline ll sub3 () {
	init();
	for (int i = 1; i <= m; ++i) {
		if (bian[i].w == -1) continue;
		q.push({bian[i].w, {bian[i].u, bian[i].v}});
	}
	dfs (1);
	return anss;
}
signed main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	int fte = 1; 
	for (int i = 1; i <= m; ++i) {
		cin >> bian[i].u >> bian[i].v >> bian[i].w;
		if (bian[i].u > bian[i].v) swap(bian[i].u, bian[i].v);
	}
	sort (bian + 1, bian + m + 1, cmp);
	for (int i = m; i >= 1; --i) {
		if (bian[i].u == bian[i - 1].u && bian[i].v == bian[i - 1].v) {
			bian[i].w = -1;
		}
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		if (c[i]) fte = 0;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	if (k == 0)  cout << sub1();
	else if (fte)     cout << sub2();
	else 		 cout << sub3();
}
