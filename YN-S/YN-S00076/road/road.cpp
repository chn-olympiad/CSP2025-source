#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int i, j, flag;
int f, t, w;
int head[10010];
int vis[10010], choose[1200000];
int cnt, ans;
int fa[10010];
queue<int> a;

struct edge2 {
	int from, to, w;
} graph[1200000];

int find(int v) {
	return fa[v] = v ? v : fa[v] = find(fa[v]);
}

void build2(int f, int t, int w) {
	graph[cnt].from = f;
	graph[cnt].to = t;
	graph[cnt++].w = w;
	graph[cnt].from = t;
	graph[cnt].to = f;
	graph[cnt++].w = w;
}

bool operator<(edge2 i, edge2 j) {
	return i.w < j.w;
}


void kruskal() {
	cnt = 0;
	for (i = 0; i < m + k * n; i++) {
		if (find(graph[m].from) == find(graph[m].to))
			continue;
		ans += graph[m].w;
		fa[graph[m].to] = graph[m].from;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < 10010; i++)
		fa[i] = i;
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &f, &t, &w);
		build2(f, t, w);
	}
	for (i = n; i < k + n; i++) {
		flag = 0;
		for (j = -1; j < n; j++) {
			scanf("%d", &w);
			if (flag == 0) {
				flag++;
				continue;
			}
			build2(i, j, w);
		}
	}
	sort(graph, graph + m + k * n);
	kruskal();
	printf("%d", ans);
	return 0;
}