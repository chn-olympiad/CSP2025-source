#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

int c[510];
int a[510];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	bool f = 1;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			a[i + 1] = 0;
			f = 0;
		} else {
			cnt++;
		}
	}
	if (cnt < m) {
		cout << 0;
	} else if (m == n && !f) {
		cout << 0;
	} else if (f) {
		int ans = 1;
		for (int i = 1; i <= m; i++) {
			ans *= i;
			ans %= mod;
		}
		cout << ans;
	} else {
		cout << 0;
	}
	return 0;
}
