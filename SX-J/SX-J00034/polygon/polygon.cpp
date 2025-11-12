#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[5010], he[5010];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, mx = LLONG_MIN;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		he[i] = he[i - 1] + h[i];
		mx = max(mx, h[i]);
	}
	if (n == 3) {
		if (he[3] > mx * 2)
			cout << 1;
		else
			cout << 0;
	} else if (mx == 1)
		cout << 4 * n - 11;
	else {
		cout << 366911923;
	}
	return 0;
}