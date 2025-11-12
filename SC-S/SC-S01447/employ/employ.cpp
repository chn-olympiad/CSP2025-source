#include <queue>
#include <string>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define fi first
#define se second
#define pii pair<ll , ll>
#define mk make_pair
#define ls x << 1
#define rs x << 1 | 1
#define ull unsigned ll
using namespace std;
ll const N = 5e2 + 10 , M = 1e6 + 10 , K = 22 , mod = 998244353;
ll n , m , c[N] , dp[M][K];
string t;
ll p(ll s){
	ll ret = 0;
	while (s) ret += (s & 1) , s >>= 1;
	return ret;
}
signed main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> t;
	t = "#" + t;
	for (int i = 1;i <= n;i ++) cin >> c[i];
	if (n <= 18){
		dp[0][0] = 1;
		for (int s = 1;s < (1 << n);s ++){
			ll num = p(s);
			if (t[num] == '1'){
				for (int i = num - 1;i >= 0;i --)
					for (int j = 1;j <= n;j ++)
						if (s & (1 << j - 1))
							if (i >= c[j]){
								dp[s][i + 1] += dp[s ^ (1 << j - 1)][i];
								if (dp[s][i + 1] >= mod) dp[s][i + 1] -= mod;
							}
							else {
								dp[s][i] += dp[s ^ (1 << j - 1)][i];
								if (dp[s][i] >= mod) dp[s][i] -= mod;
							}
			}
			else {
				for (int i = num - 1;i >= 0;i --)
					for (int j = 1;j <= n;j ++)
						if (s & (1 << j - 1)){
							dp[s][i + 1] += dp[s ^ (1 << j - 1)][i];
							if (dp[s][i + 1] >= mod) dp[s][i + 1] -= mod;
						}
			}
		}
		ll ans = 0;
		for (int i = 0;i <= n - m;i ++){
			ans += dp[(1 << n) - 1][i];
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/