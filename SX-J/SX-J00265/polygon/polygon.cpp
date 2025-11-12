#include <bits/stdc++.h>
using namespace std;
int n, mx;
int a[5010];
long long sum[5010];
long long ans;
int mod = 998244353;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i ++) {
		mx = max(a[i], a[i + 1]);
		for (int j = i + 2; j <= n; j ++) {
			mx = max(mx, a[j]);
			if ((sum[j] - sum[i - 1]) > (2 * mx)) {
				ans ++;
				ans = ans % mod;
				cout << i << ' ' << j << endl;
			}
		}
	}
	cout << ans;
	return 0;
}
