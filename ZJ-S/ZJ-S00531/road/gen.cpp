#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000 + 10 + 5;
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n = 1e4, m = 1e6, k = 10;
	freopen("road.in", "w", stdout);
	printf("%d %d %d\n", n, m, k);
	mt19937 rng(1000);
	for (int i = 1; i <= m; i++) {
		printf("%d %d %d\n", rng() % n + 1, rng() % n + 1, rng() % 1000000000 + 1);
	}
	for (int i = 1; i <= k; i++) {
		printf("%d\n", rng() % 10000000 + 1);
		for (int i = 1; i <= n; i++)
			printf("%d ", rng() % 1000000000 + 1);
	}
	return 0;
}