#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a[5001],dp[5001][10001],ans;
int kasumi(int a,int b){
	int res = 1;
	while (b){
		if (b & 1){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++){
		for (int j = 0;j <= 10000;j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i]){
				dp[i][j] += dp[i - 1][j - a[i]];
				dp[i][j] %= mod;
			}
		}
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= 10000;j++){
			dp[i][j] += dp[i][j - 1];
			dp[i][j] %= mod;
		}
	}
	for (int i = 2;i <= n;i++){
		int cnt = kasumi(2,i - 1);
		cnt -= ((((dp[i][a[i] * 2] - dp[i - 1][a[i] * 2]) % mod) + mod) % mod);
		cnt %= mod;
		cnt += mod;
		cnt %= mod;
		ans += cnt;
		ans %= mod;
	}
	printf("%lld",ans);
	return 0;
}
