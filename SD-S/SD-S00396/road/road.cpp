#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 100;
const int maxm = 1e6 + 100;
int n, m, k;
int h[maxn];
int f[maxn];
struct node {
	int nxt;
	int val;
	int to;
	int frm;
	bool operator<(const node& x) const {
		return val < x.val;
	}
} edge[maxm * 2];
int cnt = 0;
bool vis[maxn];

void add(int u, int v, int w) {
	edge[++cnt].val = w;
	edge[cnt].to = v;
	edge[cnt].frm = u;
	edge[cnt].nxt = h[u];
	h[u] = cnt;
}

int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

int kruskal(int ced) {
	int ans = 0;
	int cnt = 0;
	sort(edge + 1, edge + ced + 1);
	for(int i = 1; i<=ced; i++) {
		int u = edge[i].frm;
		int v = edge[i].to;
		int x = find(u), y = find(v);
		if(x == y) continue;
		//cout << "---" << u << "-" << v << " " << edge[i].val << '\n';
		//if(v > n && vis[v]) continue;
		//if(u > n && !vis[u]) continue;
		f[y] = x;
		if(u <= n && !vis[u]) cnt ++;
		if(v <= n && !vis[v]) cnt ++;
		ans += edge[i].val;
		vis[u] = vis[v] = 1;
		//if(cnt == n) break;
	}
	return ans;
}


signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i<=n+k+1; i++) {
		f[i] = i;
	}
	for(int i = 1; i<=m; i++) {
		int u, v, w; cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for(int i = 1; i<=k; i++) {
		int c; cin >> c;
		for(int j = 1; j<=n; j++) {
			int g; cin >> g;
			//add(j, n + i, g + c);
			//add(n + i, j, g);
		}
	}
	int ans = kruskal(cnt);
	cout << ans; 
	
	return 0;
}

