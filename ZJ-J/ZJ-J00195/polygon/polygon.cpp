#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, p = 998244353;
int n;
long long a[N], dp[N][N];
long long ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 5e3 + 1; j++) {
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= p;
			if (j + a[i + 1] <= 5e3) 
				dp[i + 1][j + a[i + 1]] += dp[i][j], dp[i + 1][j + a[i + 1]] %= p;
			else dp[i + 1][5001] += dp[i][j], dp[i + 1][5001] %= p;
		}
		for (int j = a[i + 1] + 1; j <= 5e3 + 1; j++) {
			ans += dp[i][j];
			ans %= p;
		}
	}
	cout << ans;
	return 0;
}
