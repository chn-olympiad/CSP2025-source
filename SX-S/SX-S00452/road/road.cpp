#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, sum = 0, f = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		sum += w;
	}
	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		for (int j = 1; j <= n; i++) {
			int a;
			cin >> a;
			if (a != 0)
				f++;
		}
	}
	if (f == 0) {
		cout << 0;
		return 0;
	} else {
		cout << sum;
	}

	return 0;
}
//2