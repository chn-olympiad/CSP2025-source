#include<bits/stdc++.h>
using namespace std;
#define int long long
struct P{
	int u, v, w;
}ed[2000010]; 
bool cmp(P n, P m) {
	return n.w < m.w;
}
int n, m, k, a[15][10010], fa[10010], c[15];
vector<pair<int, int> > e[10010];
int get(int x) {
	if(fa[x] != x) fa[x] = get(fa[x]);
	return fa[x]; 
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++ i) fa[i] = i;
	for(int i = 1; i <= m; ++ i) {
		int u, v, w;
		cin >> u >> v >> w;
		ed[i].u = u, ed[i].v = v, ed[i].w = w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}for(int i = 1; i <= k; ++ i) {
		cin >> c[i];
		int p = 0;
		for(int j = 1; j <= n; ++ j) {
			cin >> a[i][j];
			if(a[i][j] == 0) p = j;
		}for(int j = 1; j <= n; ++ j) {
			ed[++ m].u = p, ed[m].v = j, ed[m].w = a[i][j];
		}
	}sort(ed + 1, ed + m + 1, cmp);
	int ans = 0;
	for(int i = 1; i <= m; ++ i) {
		int fu = get(ed[i].u), fv = get(ed[i].v);
		if(fu != fv) {
			fa[fu] = fv;
			ans += ed[i].w;
		}
	}cout << ans;
} 