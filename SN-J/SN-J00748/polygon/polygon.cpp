// XGDFZ wsq
#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace wsq {
	const int N = 5005;
	const int P = 998244353;
	int n, a[N], sum[N];
	int dp[N * N];
	void main() {
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], sum[i] = sum[i-1]+a[i];
		sort(a + 1, a + n + 1);
		int cnt = 0;
		dp[0] = 1;
		for(int i = 1, j; i < n; i++) {
			dp[0] = 1;
			for(j = sum[i]; j >= a[i]; j--) {
				dp[j] += dp[j - a[i]];
				// cout << dp[i][j] << " ";
				dp[j] %= P;
			}
			if(i >= 2)
			for(j = a[i+1] + 1; j <= sum[i]; j++)
				(cnt += dp[j]) %= P;
			// cout << endl;
		}
		cout << cnt;
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T--)
		wsq::main();
	return 0;
}
// I have no egg!
