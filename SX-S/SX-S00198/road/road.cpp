#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[100010];
long long sum;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		sum += w;
	}
	for (int i = 1; i <= k; i ++) {
		int c;
		cin >> c;
		for (int j = 1; j <= n; j ++) {
			cin >> a[j];
		}
	}
	printf("%lld", sum);
	return 0;
}