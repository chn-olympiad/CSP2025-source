#include <bits/stdc++.h>
using namespace std;
int xr[500010], n, k, x, tong[3000000], ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	tong[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		xr[i] = xr[i - 1] ^ x;
		if (tong[xr[i]^k] == 1) {
			ans++;
			xr[i] = 0;
			memset(tong, 0, sizeof tong);
			tong[0] = 1;
		} else
			tong[xr[i]] = 1;
	}
	cout << ans;
	return 0;
}
