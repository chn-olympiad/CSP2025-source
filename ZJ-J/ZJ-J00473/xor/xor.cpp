#include<bits/stdc++.h>
using namespace std;
int n, k;
const int M = 5e5 + 10;
int a[M];
int f[M];
int dp[M];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool c = false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] ^ a[i];
		if (a[i] != 1) c = true;
	}
	if (!c) {
		cout << n / 2;
		return 0;
	}
	else if (n <= 2 && k == 0) {
		if (n == 1) {
			cout << 0;
			return 0;
		}
		else if (n == 2) {
			int ans = 0;
			if (a[1] == a[2]) ans++;
			cout << ans;
			return 0;
		}
	}
	else if (k <= 1) {
		if (k == 0) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) ans++;
				else if (a[i] == 1) {
					if (a[i + 1] == 1) {
						ans++;
						i++;	
					}
				}
			}
			cout << ans;
			return 0;
		}
		else if (k == 1) {
			int ans = 0;
			for (int i = 1; i <= n; i++) if (a[i] == 1) ans++;
			cout << ans;
			return 0;
		}
	}
	else { 
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1];
			for (int j = i; j >= 1; j--) {
				int s = f[i] ^ f[j - 1];
				if (s == k) {
					dp[i] = max(dp[i], dp[j - 1] + 1);
				}
			}
		}
		cout << dp[n];
	}
	return 0;
}
