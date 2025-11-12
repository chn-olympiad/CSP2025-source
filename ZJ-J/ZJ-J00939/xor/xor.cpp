/*luoguUID: 995899*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], sum[N], dp[N], ans;
map <int, int> f, g;
signed main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = a[i] ^ sum[i - 1];
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		//for (int j = 1; j <= i; j++) {
		//	dp[i] = max (dp[i], dp[j - 1]);
		//	if ((sum[i] ^ sum[j - 1]) == k)
		//		dp[i] = max (dp[i], dp[j - 1] + 1);
		//}
		dp[i] = dp[i - 1];
		dp[i] = max (dp[i], g[k ^ sum[i]] + f[k ^ sum[i]]);
		f[sum[i]] = 1;
		g[sum[i]] = max (g[sum[i]], dp[i]);
	}
	cout << dp[n];
	return 0;
}