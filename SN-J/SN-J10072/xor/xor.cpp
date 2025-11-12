#include <bits/stdc++.h>
using namespace std;
const int XN=5e5+10;
int n, k, a[XN], sum[XN], b[XN], lst[XN], dp[XN], ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(lst, -1, sizeof(lst));
	lst[0] = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1]^a[i];
		lst[sum[i]] = i;
		b[i] = lst[k^sum[i]];
//		cout << sum[i] << ' ' << lst[i] << ' ' << b[i] << "\n";
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] != -1) dp[i] = max(dp[b[i]]+1, dp[i-1]);
		else dp[i] = dp[i-1];
	}
//	for (int i = 1; i <= n; i++)
//		cout << dp[i] << ' ';
	cout << dp[n];
	return 0;
}
