#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n, m, c[505], ord[505], ans;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	bool f = 1;
	for (int i = 1; i <= n; i ++) {
		if (s[i] != '1') {
			f = 0;
			break;
		}
	}
	if (f) {
		ans = 1;
		for (int i = 2; i <= n; i ++) {
			ans = (ans * i) % mod;
			cout << ans << '\n';
		}
		cout << ans << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i ++) ord[i] = i;
	do {
		int cnt = 0, sum = 0;
		for (int i = 1; i <= n; i ++) {
			int x = ord[i];
			if (c[x] <= cnt) cnt ++;
			else {
				if (s[i] == '1') sum ++;
				else cnt ++;
			}
		}
		if (sum >= m) ans = (ans + 1) % mod;
	} while(next_permutation(ord + 1, ord + n + 1));
	cout << ans << '\n';
	return 0;
} 
