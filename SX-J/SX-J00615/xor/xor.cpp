#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], sum, s;
bool vis[500005], flag;

//int n, k, a[500005], dp[1005][1005], s[1005][1005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	for (int i = 1; i <= n; i++) {
//		s[i][i] = a[i];
//		if (a[i] == k)
//			dp[i][i] = 1;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			s[i][j] = s[i][j - 1] ^ a[j];
//		}
//	}
//	for (int i = n - 1; i >= 1; i--) {
//		for (int j = i + 1; j <= n; j++) {
//			if (s[i][j] == k)
//				dp[i][j] = dp[i + 1][j - 1] + 1;
//			else
//				dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << s[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dp[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << dp[1][n];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int t = i; t <= j; t++) {
				if (!vis[t]) {
					if (s == 0)
						s = a[t];
					else
						s = s ^ a[t];
					if (s == k) {
						sum++;
						s = 0;
						flag = 1;
					}
					vis[t] = 1;
				}
			}
			if (!flag) {
				for (int t = i; t <= j; t++)
					vis[t] = 0;
			}
		}
	}
	cout << sum;
	return 0;
}