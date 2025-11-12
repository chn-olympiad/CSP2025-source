// ¸¨ÂÖÖÐÑ§ µ­³þÜ² SN-J00692 
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010, mod = 998244353; 
int TTT = 1, n, m, res, ans, dp[N][N], a[N];

void mian()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n); dp[0][0] = 1, m = a[n];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < a[i]; j++) dp[i][j] = dp[i - 1][j];
		for(int j = a[i] + 1; j <= m; j++) ans = (ans + dp[i - 1][j]) % mod;
		
		ans = (ans + res) % mod;
		res = res * 2 % mod;
		
		for(int j = 0; j <= m; j++)
			if(j + a[i] <= m) dp[i][j + a[i]] = (dp[i - 1][j + a[i]] + dp[i - 1][j]) % mod;
			else res = (res + dp[i - 1][j]) % mod;
		
	}
	cout << ans;
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> TTT;
	while(TTT--) mian();
	return 0;
}
