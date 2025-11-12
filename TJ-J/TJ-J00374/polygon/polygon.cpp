#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[5010];
signed main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	if (a[n] == 1) {
		cout << (n - 2) * (n - 2);
	} else {
		if ((a[1] + a[2] + a[3]) > 2 * a[n]) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}
