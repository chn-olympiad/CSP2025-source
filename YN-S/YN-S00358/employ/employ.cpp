#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10, mod = 998244353;
int n, m, c[N], p[N];
string s;

signed main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			cnt++;
	}
	int ans = 1;
	if (m == 1) {
		if (cnt != 0) {
			while (n != 0) {
				ans = (ans * n) % mod;
				n--;
			}
			cout << ans;
		} else
			cout << 0;
		return 0;
	}
	if (n == m) {
		if (cnt == n) {
			cout << 1;
		} else
			cout << 0;
		return 0;
	}
	return 0;
}