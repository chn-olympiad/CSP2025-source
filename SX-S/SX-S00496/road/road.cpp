#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int cost[11], c[11][10001];

struct node {
	int u, v, w;
} a[1000001];

bool cmp(node x, node y) {
	return x.w < y.w;
}
bool f1[10001][10001];
bool f2[11][10001]

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> cost[i];
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (c[i][j] == 0) {

			}
		}
	}

	return 0;
}