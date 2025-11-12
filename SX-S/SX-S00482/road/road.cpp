#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, v, w;
} edge[2500005];

int d[10005];
int c[10005];

int find(int x) {
	while (d[x] != x)
		x = d[x];
	return x;
}

bool cmp(node a, node b) {
	return a.w < b.w;
}
set<int>s;
int cnt;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		cnt++;
		edge[cnt].u = u;
		edge[cnt].v = v;
		edge[cnt].w = w;
	}
	for (int i = 1; i <= k; i++) {
		int id = i + n;
		scanf("%d", &c[id]);
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			cnt++;
			edge[cnt].u = id;
			edge[cnt].v = j;
			edge[cnt].w = a;
		}
	}
	m = cnt;
	n += k;
	for (int i = 1; i <= n; i++)
		d[i] = i;
	sort(edge + 1, edge + m + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= m; i++) {

		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		int q = find(u);
		int p = find(v);
		if (p == q)
			continue;
		if (u > n) {
			if (find(v) != v)
				continue;
		}
		d[p] = q;
		s.insert(u);
		s.insert(v);
		ans += w;
	}
	for (int i = n - k; i <= n; i++) {
		if (s.count(i))
			ans += c[i];
	}
	printf("%d", ans);
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/
