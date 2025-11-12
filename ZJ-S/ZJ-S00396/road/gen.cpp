#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 rnd(time(0));

const int V = 1e9;

int n, m, k;

signed main() {
	assert(freopen("road.in", "w", stdout));

	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);

	n = 1000, m = 100000, k = 10;
	cout << n << ' ' << m << ' ' << k << '\n';
	for (int i = 1; i < n; ++i) {
		cout << i + 1 << ' ' << rnd() % i + 1 << ' ' << rnd() % V + 1 << '\n';
	}
	for (int i = n; i <= m; ++i) {
		int u = rnd() % n + 1, v = rnd() % n + 1;
		while (u == v) {
			u = rnd() % n + 1, v = rnd() % n + 1;
		}
		cout << u << ' ' << v << ' ' << rnd() % V + 1 << '\n';
	}
	for (int i = 1; i <= k; ++i) {
		cout << rnd() % V + 1 << ' ';
		for (int j = 1; j <= n; ++j) {
			cout << rnd() % V + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}