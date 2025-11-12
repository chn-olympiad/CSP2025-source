/*
俏也不争春
只把春来报
待到山花烂漫时
她在丛中笑
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+114514;
long long p[N];
int n, m, k;
long long ans;
int mon3tr = 0;

struct Edge {
	int u, v;
	long long w, c;

	bool operator < (const Edge &W) const {
		return W.w + W.c > w + c;
	}
} edge[N];

int find(int x) {
	if (p[x] != x) {
		p[x] = find(p[x]);
	}
	return p[x];
}

void init() {
	for (int i = 1; i <= n * 2; i++) {
		p[i] = i;
	}
}

void kruskal() {
	init();
	sort(edge + 1, edge + m + mon3tr + 1);
	int cnt = 0;
	for (int i = 1; i <= m + mon3tr; i++) {
		int a = find(edge[i].u);
		int b = find(edge[i].v);

		if (a == b) {
			continue;
		}

		cnt++;
		ans += edge[i].w + edge[i].c;
		p[a] = b;

		if (edge[i].c) {
			n++;
			edge[i].c = 0;
			for (int j = i + 1; j <= m + mon3tr + 1; j++) {
				if (edge[j].u == edge[i].u) {
					edge[j].c = 0;
				}
			}
			sort(edge + i, edge + m + mon3tr + 1);
		}

		if (cnt == n - 1) {
			break;
		}
	}
}

int main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &edge[i].u, &edge[i].v, &edge[i].w);
		edge[i].c = 0;
	}

	for (int i = 1; i <= k; i++) {
		long long c;
		scanf("%lld", &c);
		for (int j = 1; j <= n; j++) {
			long long w;
			scanf("%lld", &w);
			edge[++mon3tr].u = n + i + 1;
			edge[mon3tr].v = j;
			edge[mon3tr].w = w;
			edge[mon3tr].c = c;
		}
	}

	kruskal();

	printf("%lld\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
