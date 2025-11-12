#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;

const int Mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 5);
	int mx = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if (n == 3) {
		int sum = a[1] + a[2] + a[3];
		int m = max({a[1], a[2], a[3]}) * 2;
		if (sum > m) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	} else {
		int ans = 0;
		for (int i = 1; i <= n - 2; i ++) {
			ans += i;
			ans %= Mod;
		}
		cout << ans << endl;
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
// AKCSP-J2025!!!
