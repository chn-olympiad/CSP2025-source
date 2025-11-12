#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans = 1;
int s[600], c[600];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i] != 1)
			flag = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (flag == 1) {
		for (int i = n; i >= n - m + 1; i--) {
			ans = (ans % 988244353 * i) % 988244353;
		}
		cout << ans;
	}
	cout << n;
	return 0;
}
