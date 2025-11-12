#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

typedef pair<int, int> pii;
const int N = 1e4 + 50;
struct Node {
	int u, v, l;
};
int n, m, k, c[N], a[20][N], ans = 1ll << 60, vis[N], len;
vector<Node> edge, e;
vector<int> s;
struct Dest {
	int fa[N];
	void init() {
		for(int i = 1; i <= n + k; i++)
			fa[i] = i;
	}
	int findset(int x) {
		if(fa[x] == x) return x;
		return fa[x] = findset(fa[x]);
	}
	void Union(int x, int y) {
		int fx = findset(x), fy = findset(y);
		fa[fx] = fy;
	}
}s1;

bool cmp(const Node &a, const Node &b) {
	return a.l == b.l ? c[a.u] < c[b.u] : a.l < b.l;
}

int Kruskal(bool f) {
	s1.init();
	int anss = 0;
	for(int i = 0; i < len; i++) {
		int u = edge[i].u, v = edge[i].v, l = edge[i].l;
		if(!vis[u] || !vis[v]) continue;
		if(s1.findset(u) != s1.findset(v)) {
			s1.Union(u, v);
			anss += l;
			if(f) s.pb(i);
		}
	}
	return anss;
}

void dfs(int p, int sum) {
	if(p > k) {
//		for(int i = 1; i <= k; i++) printf("%lld ", vis[i + n]);
//		printf("%lld\n", Kruskal()); 
		ans = min(ans, sum + Kruskal(0));
		return;
	}
	dfs(p + 1, sum);
	vis[p + n] = 1;
	dfs(p + 1, sum + c[p + n]);
	vis[p + n] = 0;
}


inline int rd() {
	int x = 0;
	char ch = getchar();
	while(!(ch >= '0' && ch <= '9')) ch = getchar();
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = rd(), m = rd(), k = rd();
	for(int i = 1; i <= n; i++) vis[i] = 1;
	for(int i = 1, u, v, w; i <= m; i++) {
		u = rd(), v = rd(), w = rd();
		edge.pb({u, v, w});
	}	
	sort(edge.begin(), edge.end(), cmp);
	len = edge.size();
	Kruskal(1);
	for(auto i : s)
		e.pb(edge[i]);
	edge.clear(), edge = e;
	for(int i = 1; i <= k; i++) {
		c[i + n] = rd();
		for(int j = 1; j <= n; j++) {
			a[i][j] = rd();
			edge.pb({i + n, j, a[i][j]});
		}
	}
	sort(edge.begin(), edge.end(), cmp);
	len = edge.size();
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}
