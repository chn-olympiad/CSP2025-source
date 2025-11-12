#include <iostream>
#include <algorithm>
#define ll long long
#define MOD 998244353

using namespace std;

int n, arr[5008];
ll dp[5008][5008];
// dp[i][j]表示排好序后前i个数总和为j的情况数 
ll ans = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 5002; j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][min(j + arr[i - 1], 5002)] += dp[i - 1][j];
			dp[i][j] %= MOD;
			if (j > arr[i] and i != n) {
				ans += dp[i][j];
				ans %= MOD;
			}
		}
	}
	
	cout << ans << "\n";
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

