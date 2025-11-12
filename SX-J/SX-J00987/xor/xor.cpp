#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n, k, a[100100], b, ans, last = -1, dp[100100], sss, min_sss;

ll check(ll i) {
	ll l_s = -1;
	ll l_t = a[i];
	for (ll j = i + 1; j <= n; j++) {
		if (l_s == -1) {
			l_s = a[j];
		} else {
			l_s = (l_s ^a[j]);
		}
		l_t = (l_t ^a[j]);
		if (l_s == k) {
			return j;
		} else if (l_t == k) {
			return j;
		}
	}
	return -1;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (ll i = 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		if (a[i] == k) {
			if (dp[i] <= dp[i - 1]) {
				dp[i]++;
			}
		} else {
			sss = check(i);
			dp[sss] = dp[i] + 1;
		}
	}
	cout << dp[n];
	return 0;
}
