#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int T;
int n;
int a[N], b[N], c[N];

signed main(void) {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0;
		int q = 0, w = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			q += b[i], w += c[i];
		}
		if (q == 0 && w == 0) {
			sort(a + 1, a + n + 1);
			for (int i = 1; i <= n / 2; i++)
				ans += a[n - i + 1];
			cout << ans << "\n";
		} else if (w == 0) {
			sort(a + 1, a + n + 1);
			sort(b + 1, b + n + 1);
			for (int i = 1; i <= n / 2; i++)
				ans += a[n - i + 1] + b[n - i + 1];
			cout << ans << "\n";
		} else {
			for (int i = 1; i <= n; i++) {
				ans += max(a[i], max(b[i], c[i]));
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
/*
3
4
1 0 0
2 0 0
3 0 0
7 0 0
4
4 0 0
1 0 0
6 0 0
9 0 0
4
3 0 0
1 0 0
9 0 0
2 0 0
*/