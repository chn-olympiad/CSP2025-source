#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5005];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0, s = -1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s = max(s, a[i]);
		sum += a[i];
	}
	if (sum > 2 * s) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
