#include <bits/stdc++.h>
using namespace std;
//)!$*#@$*$%%*
int a[5005];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (long long i = 0; i < (1ll << n); i++) {
		int sum = 0, maxn = 0, cnt = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				cnt++;
				sum += a[j];
				maxn = max(maxn, a[j]);
			}
		} 
		if (cnt >= 3 && sum > maxn * 2) ans = (ans + 1) % 998244353; 
	}
	cout << ans << endl;
	return 0;
}
