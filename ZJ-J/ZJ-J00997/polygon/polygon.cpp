#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans, MOD = 998224353;
int main(void) {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < (1 << n); i++) {
		int Last = 0, tmp = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) {
				Last = a[j + 1];
				tmp += a[j + 1];
			}
		if (tmp > 2 * Last)
			ans = (ans + 1) % MOD;
	}
	cout << ans << endl;
	return 0;
}
