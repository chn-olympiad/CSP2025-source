#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
int bu[100005];
map<pair<int, int>, int> ma;
map<pair<int, int>, int> mf;
bool f[100005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u > v)
			swap(u, v);
		if (mf[ {u, v}] == 0) {
			ma[ {u, v}] = w;
			mf[ {u, v}] = 2;
		}
		ma[ {u, v}] = min(ma[ {u, v}], w);
	}
	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		bu[i] = c;
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (n + i > j)
				ma[ {j, n + i}] = x;
			else
				ma[ {n + i, j}] = x;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += ma[ {i, j}];
		}

	}
	cout << ans - (n + k) / 2 * 3;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
