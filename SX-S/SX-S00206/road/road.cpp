#include <bits/stdc++.h>
using namespace std;

struct node {
	int u;
	int v;
	int w;
} a[1000010];
long long c[1000010];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> c[i];
		}
	}
	if (k == 0) {
		cout << n;
		return 0;
	}
	return 0;
}
