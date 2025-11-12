#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5005], sum[5005];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	} else if (n == 3 && a[1] + a[2] > a[3]) {
		cout << 1;
		return 0;
	} else if ( n == 3) {
		cout << 0;
		return 0;
	}
	return 0;
}