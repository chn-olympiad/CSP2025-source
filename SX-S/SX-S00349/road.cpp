#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int u[10000001], v[10000001], w[10000001];
int c[101][100001];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i; i <= m; i++) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	}
	printf("%d", m);
	return 0;
}
