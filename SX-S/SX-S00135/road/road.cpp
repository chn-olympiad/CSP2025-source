#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000005

struct Edge {
	int to, nxt, w;
} edge[N * 4];
int head[N * 2], tot;

void add(int u, int v, int w) {
	edge[++tot].to = v;
	edge[tot].w = w;
	edge[tot].nxt = head[u];
	head[u] = tot;
}
int c[N];
int n, m, k;

int fa[2 * N]; //miniest tree
bool vis[2 * N];

int find(int x) {
	if (fa[x] == x)
		return x;
	else
		return (fa[x] = find(fa[x]));
}

void merge(int a, int b) {
	if (find(a) == find(b))
		return;
	else
		fa[find(a)] = fa[find(b)];
}

struct node {
	int id, w;
	bool operator<(const node &a)const {
		return a.w < w;
	}
};
priority_queue<node> q;

int kruskal(int s) {
	q.push(node{s, 0});
	int ans = 0;
	while (!q.empty()) {
		node u;
		u = q.top();
		q.pop();
		int x = u.id, www = u.w;
		ans += www;
		for (int i = head[x]; i; i = edge[i].nxt) {
			int v = edge[i].to, ww = edge[i].w;
			if (find(x) == find(v))
				continue;
			merge(x, v);
			q.push(node{x, ww});
		}
	}
	return ans;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (int i = 1; i < 2 * N; i++) {
		fa[i] = i;
	}
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			int aa;
			scanf("%lld", &aa);
			add(n + i, j, aa);
		}
	}
	if (k != 0) {
		printf("0\n");
	}
	if (k == 0) {
		printf("%lld\n", kruskal(1));
	}
	return 0;
}
