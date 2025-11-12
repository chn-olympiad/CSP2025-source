#include <bits/stdc++.h>
using namespace std;
long long n, m, k, q, w, e;
long long maxn;
long long a[10010][10010];

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> q >> w >> e;
		if (a[q][w] != 0) {
			a[q][w] = min(a[q][w], e);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (i == j)
				continue;
			maxn += a[i][j];
		}
	}
	cout << maxn << endl;
	return 0;
}
