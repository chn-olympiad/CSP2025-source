#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int n, m;

int main() {
	assert(freopen("employ.in", "w", stdout));
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	n = rng() % 3 + 1;
	m = rng() % n + 1;
	cout << n << " " << m << "\n";
	for (int i = 1; i <= n; ++i) {
		// cout << (rng() & 1);
		cout << 1;
	}
	cout << "\n";
	for (int i = 1; i <= n; ++i) {
		cout << rng() % (n + 1) << " \n"[i == n];
	}
	return 0;
}