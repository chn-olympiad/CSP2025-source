#include <bits/stdc++.h>
using namespace std;

struct node {
	int to;
	long long w;
	bool operator < (const node &cnt)const {
		return w > cnt.w;
	}
};
vector<node>g[10010];
priority_queue<node>q;
int vis[10010];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int a, b;
		long long c;
		scanf("%d%d%lld", &a, &b, &c);
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	q.push({1, 0});
	int cnt = 0;
	long long sum = 0;
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		int u = t.to;
		if (vis[u] == 1)
			continue;
		vis[u] = 1;
		//printf("%d %lld\n", u, t.w);
		cnt++;
		sum += t.w;
		if (cnt == n) {
			printf("%lld", sum);
			break;
		}
		for (auto id : g[u]) {
			int v = id.to;
			if (vis[v] == 1)
				continue;
			long long w = id.w;
			q.push({v, w});
		}
	}
	return 0;
}
