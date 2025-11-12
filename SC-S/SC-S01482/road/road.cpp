#include <bits/stdc++.h>
#define int long long
#define ls p * 2
#define rs p * 2 + 1
#define mid ((l + r) / 2)
#define lson ls, l, mid
#define rson rs mid + 1, r
using namespace std;
const int M = 1e6 + 10, N = 1e4 + 10, mod = 998244353;
int n, m, k, c[20], a[20][N];
int ans[N];
bool vis[N];
vector<pair<int, int>> g[M];
queue<int> q;

void bfs() {
	while(q.size()) {
		int u = q.front();q.pop();
		vis[u] = 1;
		for(auto e : g[u]) {
			int v = e.first, w = e.second;
			if(vis[v]) continue;
			ans[v] = min(ans[v], w);
			q.push(v);
		}
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1;i <= k;i++) {
		cin >> c[i];
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= n;i++) ans[i] = 0x3f3f3f3f;
	q.push(1);
	bfs();
	int tot = 0;
	for(int i = 1;i <= n;i++) {
		if(ans[i] == 0x3f3f3f3f) continue;
		tot += ans[i];
	}
	if(k == 0) {
		cout << tot;
		return 0;
	}
	for(int i = 1;i <= k;i++) {
		int num = 0, mn = 0x3f3f3f3f;
		for(int j = 1;j <= n;j++) {
			if(a[i][j] != 0) ans[j] = min(ans[j], a[i][j]);
			if(a[i][j] < mn and a[i][j] != 0) {
				mn = a[i][j];
			}
			if(a[i][j] == 0) num = j;
		}
		ans[num] = min(ans[num], mn);
	}
	tot = 0;
	for(int i = 2;i <= n;i++) {
		if(ans[i] == 0x3f3f3f3f) continue;
		tot += ans[i];
	}
	cout << tot;
	return 0;
}