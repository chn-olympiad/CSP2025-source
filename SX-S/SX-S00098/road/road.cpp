#include <bits/stdc++.h>
using namespace std;
int tot = 0;
int head[1000005], w[15];

struct node {
	int w;
	int to;
	int nxt;
} edge[1000005];

void add(int u, int v, int w) {
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].nxt = head[u];
	head[u] = tot++;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	for (int i = 1; i <= k; i++) {
		cin >> w[i];
		for (int i = 1; i <= 4; i++) {
			int a, b, c;
			cin >> a >> b >> c;
		}
	}
	return 0;
}