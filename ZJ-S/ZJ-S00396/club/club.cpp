#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 5;

int n;

int a[3][N];

int b[3][N], len[3];

void solve() {
	cin >> n;
	len[0] = len[1] = len[2] = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[0][i] >> a[1][i] >> a[2][i];
		if (a[0][i] >= a[1][i] && a[0][i] >= a[2][i]) {
			ans += a[0][i];
			b[0][++len[0]] = a[0][i] - max(a[1][i], a[2][i]);
		}
		else if (a[1][i] >= a[0][i] && a[1][i] >= a[2][i]) {
			ans += a[1][i];
			b[1][++len[1]] = a[1][i] - max(a[0][i], a[2][i]);
		}
		else {
			ans += a[2][i];
			b[2][++len[2]] = a[2][i] - max(a[1][i], a[0][i]);
		}
	}
	int tag = -1;
	if (len[0] > n / 2)  {
		tag = 0;
	}
	else if (len[1] > n / 2) {
		tag = 1;
	}
	else if (len[2] > n / 2) {
		tag = 2;
	}
	if (tag != -1) {
		sort(b[tag] + 1, b[tag] + len[tag] + 1);
		for (int i = 1; i <= len[tag] - n / 2; ++i) {
			ans -= b[tag][i];
		}
	}
	cout << ans << '\n';
}

int main() {
	assert(freopen("club.in", "r", stdin));
	assert(freopen("club.out", "w", stdout));

	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}