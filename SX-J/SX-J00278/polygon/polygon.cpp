#include <bits/stdc++.h>
using namespace std;
int n;
long long a[5005], s[5005];
const int mod = 998244353;
long long f[50005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	long long ans = 0, maxn = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			maxn = max(maxn, a[i]);
			if (j >= 3 && s[j] - s[i - 1] > 2 * maxn) {
				ans++;
				ans %= mod;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
