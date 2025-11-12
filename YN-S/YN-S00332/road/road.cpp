#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
int n, m, k;
ll ans, d[2 * N], a[N];
bool vis[2 * N];

struct node {
	int v;
	ll w;
};

vector<node>g[2 * N];
node pre[2 * N];
bool operator > (const node &A, const node &B) {
	return A.w > B.w;
}
priority_queue<node, vector<node>, greater<node> >q;

void prim(int t) {
	memset(vis, 0, sizeof(vis));
	memset(d, 0x3f, sizeof(d));
	d[t] = 0;
	q.push({t, 0});
	while (q.size() != 0) {
		int now = q.top().v;
		q.pop();
		if (vis[now] == true) {
			continue;
		}
		vis[now] = true;
		int sz = g[now].size();
		for (int i = 0; i < sz; i++) {
			int tv = g[now][i].v;
			ll tw = g[now][i].w;
			if (vis[tv] == true) {
				continue;
			}
			if (d[now] + tw < d[tv]) {
				d[tv] = d[now] + tw;
				pre[tv] = {now, tw};
				q.push({tv, d[tv]});
			}
		}
	}
}

void getans(int t) {
	if (pre[t].v == 0 || vis[t] == true) {
		return;
	}
	ans += pre[t].w;
	vis[t] = true;
	getans(pre[t].v);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	memset(d, 0x3f, sizeof(d));
	while (m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &a[i]);
		for (int j = 1; j <= n; j++) {
			ll w;
			scanf("%lld", &w);
			g[j].push_back({i + n, w});
			g[i + n].push_back({j, w});
		}
	}
	prim(1);
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n + k; i++) {
		getans(i);
	}
	printf("%lld", ans);
	return 0;
}