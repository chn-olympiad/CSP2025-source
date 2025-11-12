#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum0 = 0, sum1 = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			sum0++;
		} else {
			sum1++;
		}
	}
	if (k == 0) {
		cout << sum0;
	} else {
		cout << sum1;
	}
	return 0;
}
