#include <bits/stdc++.h>
using namespace std;

int n, m, c[505], a[505], minn = 2, ans = 1, cnt = -1;
const int mod = 998244353;
bool flag = true;
string s;

int main() {
	freopen("empoly.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		a[i + 1] = s[i] - '0';
		minn = min(minn, a[i + 1]);
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[i];
		if (c[i] == 0) {
			cnt++;
		}
	}
	if (minn == 1 || m == 1) {
		for (int i = 1; i <= n; i++) {
			ans = ans * i % mod;
		}
		cout << ans % mod;
	} else if (m == n) {
		if (cnt > 0) {
			cout << 0;
		} else {
			for (int i = 1; i <= n; i++) {
				ans = ans * i % mod;
			}
			cout << ans % mod;
		}
	}

	return 0;
}
