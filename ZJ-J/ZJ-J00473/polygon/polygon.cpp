#include<bits/stdc++.h>
using namespace std;
int n;
const int M = 5e3 + 10;
const int mod = 998244353;
int a[M];
long long f[M];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cin.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool c = false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) c = true;
	}
	if (!c && n >= 3) {
		long long ans = 1;
		for (int i = 3; i <= n; i++) {
			long long sum = 1;
			long long an1 = 1;
			for (int j = 1; j <= i; j++) sum *= j, sum %= mod;
			for (int j = n - i + 1; j <= n; j++) {
				an1 *= j;
				an1 %= mod;
			}
			an1 /= sum;
			ans += an1;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	else if (n <= 3) {
		if (n < 3) {
			cout << 0;
			return 0;
		}
		else {
			int m = max(a[1], max(a[2], a[3]));
			int sum = a[1] + a[2] + a[3];
			if (2 * m < sum) cout << 1;
			else cout << 0;
			return 0;
		}
	}
	else cout << 0;
	return 0;
}
