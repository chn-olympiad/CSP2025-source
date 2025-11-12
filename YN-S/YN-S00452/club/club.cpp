#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
LL s, n, m, q, x = 0;
signed long long max, ans, flg, cnt, min;
LL a[N];

signed main() {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> n >> m  >> x >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> n;
		for (int j = 1; j <= i; ++j) {
			cin >> flg;
			if (ans = std::max(ans, x)) {
				ans++;
			} else {
				--ans;
				cout << ans << endl;
			}
			if (flg) {
				//cout << ans;
			}

		}
	}
	cout << ans << endl;
	return 0;
}