#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[15];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	int mx = max({a[1], a[2], a[3]});
	if (mx * 2 < a[1] + a[2] + a[3]) {
		cout << 1;
		return 0;
	} else {
		cout << 0;
		return 0;
	}
	cout << 1;
	return 0;
}
