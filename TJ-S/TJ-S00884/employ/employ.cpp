#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define int long long
using namespace std;
int n, m, cnt1, cnt0, ans, a[505], c[505];
signed main() {
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c ^ 48) cnt1++;
		else cnt0++;
	}
	for (int i = 1; i <= cnt0; i++) a[i] = 0;
	for (int i = cnt0 + 1; i <= n; i++) a[i] = 1;
	for (int i = 1; i <= n; i++) cin >> c[i];
	do {
		int cnt = 0, n2 = n;
		for (int i = 1; i <= n; i++) {
			if (!a[i]) cnt++, n2--;
			else if (cnt >= c[i]) n2--;
		}
		if (n2 == m) ans = (ans + 1) % 998244353;
	} while (next_permutation(a + 1, a + 1 + n));
	cout << ans % 998244353 << '\n';
	return 0;
}

