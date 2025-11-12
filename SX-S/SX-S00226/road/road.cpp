#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+10;
const int M = 1e4+20;
ll m, n, k, head[(M + N) * 2], num = 0, c[10020], ans = LLONG_MAX;
int vis[N + 10];
map<ll, int> ma;

struct edg {
	int nxt, to, w;
} edge[(M + N) * 2];

void add(ll from, ll to, ll w) {
	num++;
	edge[num].to = to;
	edge[num].w = w;
	edge[num].nxt = head[from];
	head[from] = num;
}

int comp(edg a, edg b) {
	return a.w > b.w;
}

int check() {
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			return 0;
	}
	return 1;
}

void bfs(int f) {
	queue<ll> q;
	q.push(f);
	q.push(0);
	q.push(0);
	vis[1] = 0;
	while (!q.empty() && !check()) {
		ll a, b, fr;
		a = q.front();
		q.pop();
		b = q.front();
		q.pop();
		fr = q.front();
		q.pop();
		for (ll i = head[a]; i != 0; i = edge[i].nxt) {
			if (!ma[i] && edge[i].to != fr) {
				q.push(edge[i].to);
				q.push(edge[i].w + b);
				q.push(a);
				ma[i] = 1;
				vis[edge[i].to] = 1;
				if (check()) {
					ans = min(ans, b + edge[i].w);
				}
			}
			if (ma[i] && edge[i].to != fr) {
				q.push(edge[i].to);
				q.push(b);
				q.push(a);
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = n + 1; i <= n + k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			ll a;
			scanf("%lld", &a);
			add(i, j, a + c[i]);
			add(j, i, a + c[i]);
		}
	}
	sort(edge, edge + num + 1, comp);
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	printf("%lld", ans);
	return 0;
}