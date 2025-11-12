#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll, int> >vec[110010];
priority_queue<pair<ll, int> >que;
ll w;
ll n, m, k;
int vis[1100010];
ll dis[1100010];

void dji() {
	memset(dis, 127, sizeof dis);
	dis[1] = 0;
	que.push({0, 1});
	while (que.size()) {
		auto t = que.top();
		int u = t.second;
		que.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto a : vec[u]) {
			ll w = a.first;
			int v = a.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				que.push({-dis[v], v});
			}
		}
	}
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int  u, v;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%lld", &u, &v, &w);
		if (u == v)
			continue;
		vec[u].push_back({w, v});
		vec[v].push_back({w, u});
	}
	for (int i = m + 1; i <= m + k + 1; ++i) {
		scanf("%d", &u);
		for (int j = 1; j <= n; ++j) {
			scanf("%lld", &w);
			vec[u].push_back({2 * w, j});
			vec[j].push_back({2 * w, u});
		}

		//	vec[v].push_back({w, u});
	}
	dji();
	cout << dis[n] << "\n";
	return 0;
}