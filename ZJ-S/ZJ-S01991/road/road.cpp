#include <bits/stdc++.h>
using namespace std;

long long g[1010][1010];
long long c[20][1010];
bool vis[1010];
bool a[20];
long long n, m, k;
long long ans = 0;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (long long i = 1; i <= m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}
	for (long long i = 1; i <= k; i++) {
		for (long long j = 0; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	priority_queue<pair<pair<long long, long long>, pair<long long, long long>>, vector<pair<pair<long long, long long>, pair<long long, long long>>>, greater<pair<pair<long long, long long>, pair<long long, long long>>>> q;
	vis[1] = 1;
	for (long long i = 2; i <= n; i++) {
		long long minn = 1e9;
		if (g[1][i] != 0) minn = g[1][i];
		int id = 0;
		for (long long j = 1; j <= k; j++) {
			if (c[j][0] + c[j][1] + c[j][i] < minn) id = j;
			minn = min(minn, c[j][0] + c[j][1] + c[j][i]);
		}
		q.push({{minn, id}, {1, i}});
	}
	while(!q.empty()) {
		long long u = q.top().second.first, v = q.top().second.second, w = q.top().first.first, x = q.top().first.second;
		q.pop();
		if (vis[u] && vis[v]) continue;
		if(x != 0) c[x][v] = 0;
		if(x != 0) c[x][u] = 0;
		ans += w;
		vis[v] = 1;
		for (long long i = 1; i <= n; i++) {
			if (vis[i]) continue;
			long long minn = 1e9;
			if (g[v][i] != 0) minn = g[v][i];
			int id = 0;
			for (long long j = 1; j <= k; j++) {
				if (c[j][0] + c[j][v] + c[j][i] < minn) id = j;
				minn = min(minn, c[j][0] + c[j][v] + c[j][i]);
			}
			q.push({{minn, id}, {v, i}});
		}
		if (a[x] == 0 && x != 0)
			for (long long i = 1; i <= n; i++) {
				if (vis[i]) continue;
				q.push({{c[x][i], 0}, {v, i}});
			}
		if(x != 0) a[x] = 1;
	}
	cout << ans << endl;
	return 0;
}
