#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
const int N = 20;
int dp[1 << N][N];
int n, m; string s;
int c[505];

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < n; i ++) cin >> c[i];
	if (n <= 20){
		dp[0][0] = 1;
		for (int i = 1; i < (1 << n); i ++){
			for (int R = 0; R <= n; R ++)
				for (int k = 0; k < n; k ++){
					if (!((i >> k) & 1)) continue;
					int z = __builtin_popcount(i) - 1;
					int lst = (1 << k) ^ i;
					if (s[z] == '0'){
						if (R > 0)
						dp[i][R] = (dp[i][R] + dp[lst][R - 1]) % MOD;
					} else {
						if (R - 1 >= c[k])
							dp[i][R] = (dp[i][R] + dp[lst][R - 1]) % MOD;
						else if (R - 1 >= 0)
							dp[i][R - 1] = (dp[i][R - 1] + dp[lst][R - 1]) % MOD;
					}
				}
		} int ans = 0;
		for (int i = (n - m); i >= 0; i --)
			ans = (ans + dp[(1 << n) - 1][i]) % MOD;
		cout << ans;	
	} else {
		int tmp = 1;
		for (int i = 1; i <= n; i ++) tmp = (tmp * i) % MOD;
		cout << tmp;
	}
	return 0;
}