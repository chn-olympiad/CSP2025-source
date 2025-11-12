#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 20;
int n, m, k, x[N], f[N], res, ans;
bool vis[N];
int find(int x) {
	if(f[x] == x) return f[x];
	return f[x] = find(f[x]);
}
struct node{
	int u, v, w;
};
bool check() {
	for (int i = 1; i < n; i ++) {
		if(find(i) != find(i + 1)) return 0;
	}
	return 1;
}
priority_queue<node> q;
bool operator <(node a, node b) {
	return a.w > b.w;
}
vector<node> g[N];

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i ++) {
		f[i] = i;
	}
	
	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		q.push({u, v, w});
	}
	for (int i = 1; i <= k; i ++) {
		cin >> x[i];
		for (int j = 1; j <= n; j ++) {
			int w;
			cin >> w;
			q.push({i + n, j, w});
		}
	}
	while(!q.empty()) {
		node r = q.top();
		q.pop();
		if(check()) {
			break;
		}
		if(find(f[r.u]) != find(f[r.v])) {
			ans += r.w;
			if(r.u > n) vis[r.u - n] = 1;
			if(r.v > n) vis[r.v - n] = 1;
			res ++;
			f[find(r.u)] = find(f[r.v]);
		}
	}
	for (int i = 1; i <= k; i ++) {
		if(vis[i]) ans += x[i];
	}
	cout << ans;
	return 0;
}