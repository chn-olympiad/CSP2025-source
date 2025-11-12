
#include<bits/stdc++.h>
using namespace std;
int n, m, k;
const int N = 1e4 + 10;
struct edge{
	int to;
	long long w;
	const bool operator < (const edge e) const {
		return w > e.w;
	}
};
vector<edge> edges[N];
long long c[20], a[20][N];
bool vis[N];
long long dist[N];
void prim(int s) {
	for (int i = 0; i < N; i++)
		dist[i] = 1e18;
	long long ans = 0;
	int cnt = 0;
	priority_queue<pair<edge, int> > q;
	q.push({{1, 0}, 0});
	
	while (cnt < n) {
		edge e = q.top().first;
		int visc = q.top().second;
		q.pop();
		if (vis[e.to])
			continue;
		vis[e.to] = visc;
		cnt++;
		ans += e.w;
		cout << e.to << ' ' << e.w << ' ' << visc << endl;
		if (cnt == n)
			break; 
		int u = e.to;
		for (int i = 0; i < (int)edges[u].size(); i++) {
			if (!vis[edges[u][i].to])
				if (edges[u][i].w <= dist[edges[u][i].to])
					q.push({edges[u][i], visc}), dist[edges[u][i].to] = edges[u][i].w;
		}
		if (k == 0)
			continue;
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				if (!vis[j]) {
					if ((visc & (1 << (i - 1))) != 0) {
						if (a[i][j] <= dist[j])
							q.push({{j, a[i][j]}, visc}), dist[j] = a[i][j];
					} else {
						if (c[i] + a[i][u] + a[i][j] <= dist[j]) {
							q.push({{j, c[i] + a[i][u] + a[i][j]}, (visc | (1 << (i - 1)))});
							dist[j] = c[i] + a[i][u] + a[i][j];
						}
						
					}
				}
			}
		}
		
	}
	cout << ans;
	return ;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	prim(1);
	return 0;
}
