#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
struct road{
	int to, w;
};
int n, m, k;
long long ans;
vector<road> edge[maxn];
int c[100];
bool cc[100], flag[maxn];
vector<road> q;
bool cmp(road x, road y) {
	return x.w <= y.w;
}
void bfs() {
	q.push_back({1,0});
	long long sum = 0, go = 1;
	while (!q.empty()) {
		road u = q.front(); q.pop_back();
		sum += u.w;
		for (int i = 0; i < edge[u.to].size(); i++) {
			int v = edge[u.to][i].to;
			if (v > n && !cc[v - n]) q.push_back({v, edge[u.to][i].w}), cc[v - n] = true;
			else if (v <= n) go++;
		}
		sort(q.begin(), q.end(), cmp);
		if (go == n) ans = min(ans, sum);
	}
}
int main () {
//	freopen ("road.in", "r", stdin);
//	freopen ("road.out", "w", stdout);
	std::ios::sync_with_stdio (false);
	std::cin.tie (0); std::cout.tie (0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[x].push_back({y, z});
		edge[y].push_back({x, z});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			edge[n+i].push_back({j, x});
			edge[j].push_back({n+i, x});
		}
	}
	for (int i = 1; i <= n + k; i++) {
		sort(edge[i].begin(), edge[i].end(), cmp);
	}
	ans = LONG_LONG_MAX;
	bfs();
	cout << ans;
	return 0;
}

