#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3+10, mod = 998244353;
ll n, a[N], sum[N], ans = 1;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	if (n == 3) {
		if ((a[1] + a[2] + a[3]) > a[3] * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		for (int i = 3; i <= n; i++) {
			ll cnt = 1;
			for (int j = n; j >= n - i + 1; j--) {
				cnt *= j;
				cnt %= mod;
			}
			for (int j = i; j >= 2; j--) {
				cnt /= j;
			}
			ans += cnt;
		}
		cout << ans;
	}
	return 0;
}
