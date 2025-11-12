#include <bits/stdc++.h>
using namespace std;
const int N = 500, mod = 998244353;
using ll = long long;
int a[N + 5], c[N + 5], idx[N + 5];
char s[N + 5];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	cin >> s + 1;
//	bool fl = 1;
//	for (int i = 1; i <= n; i++) fl &= (s[i] == '1');
	for (int i = 1; i <= n; i++) cin >> c[i];
//	if (fl) {
//		int cnt = 0;
//		for (int i = 1; i <= n; i++)
//			if (c[i] != 0) ++cnt;
//		if (cnt < m) { cout << 0 << '\n'; return 0; }
//		int fac = 1;
//		for (int i = 1; i <= n; i++) fac = 1ll * fac * i % mod;
//		cout << fac << '\n';
//		return 0;
//	}
	for (int i = 1; i <= n; i++) idx[i] = i;
	int ans = 0;
	do {
		int ok = 0, fail = 0;
		for (int i = 1; i <= n; i++) {
			if (fail >= c[idx[i]]) fail++;
			else {
				ok += (s[i] == '1');
				fail += (s[i] == '0');
			}
		}
		ans += (ok >= m);
	} while (next_permutation(idx + 1, idx + n + 1));
	cout << ans << '\n';
	return 0;
}
