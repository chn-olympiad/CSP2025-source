#include <bits/stdc++.h>
using namespace std;
int n, k, num = 0, x = 0;
int a[500005], s[500005];
int dp[500005];//前i个最大

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = (s[i - 1] ^ a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			x = 0;
			if ((s[i]^s[j - 1]) == k)
				x = 1;
			dp[i] = max(dp[i], dp[j - 1] + x);
		}
	}
	cout << dp[n];
	return 0;
}
//Hurray! My dynamic programming works!