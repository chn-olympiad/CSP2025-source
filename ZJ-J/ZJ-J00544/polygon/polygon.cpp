#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 5e3 + 10, mod = 998244353;

ll n, a[N], dp[N][N], qmi[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	qmi[0] = 1;
	for (ll i = 1; i <= n; i++) qmi[i] = qmi[i - 1] * 2 % mod;
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= a[n]; j++) {
			if (j < a[i]) dp[i][j] = qmi[i - 1];
			else dp[i][j] = dp[i - 1][j - a[i]];
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
		}
	}
	ll ans = 0;
	for (ll i = 3; i <= n; i++) ans = (ans + dp[i - 1][a[i]]) % mod;
	cout << ans;
	
	return 0;
}
