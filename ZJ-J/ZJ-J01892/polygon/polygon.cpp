#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int a[5005], b[5005], n;
int dp[5005][5005];
int js[5005];
int fjs[5005];
//int dpzj[5005][5005];
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] += a[i];
		b[i] += b[i-1];
	}
	sort(a+1, a+1+n);
	if(n >= 500 && a[n] == 1){
		js[1] = 1;
		for(int i = 2;i <= n;i++){
			js[i] = ((js[i-1]%mod)*(i%mod))%mod;
		}
		fjs[1] = n;
		for(int i = 2;i <= n;i++){
			fjs[i] = ((fjs[i-1]%mod)*((n-i+1)%mod))%mod;
		}
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans += ((fjs[i]/js[i])%mod);
			ans %= mod;
		}
		cout << ans%mod << endl;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= a[i];j++){
			dp[i][j] = 1<<(i-1);
		}
	}
	for(int i = 2;i <= n;i++){
		for(int j = a[i]+1;j <= b[i];j++){
			for(int k = 1;k < i;k++){
				dp[i][j] += dp[k][j-a[i]];
				dp[i][j] %= mod;
			}
		}
	}
	int ans = 0;
	for(int i = 3;i <= n;i++){
		//cout << dp[i][2*a[i]+1] << endl;
		ans += dp[i][2*a[i]+1]%mod;
	}
	cout << ans%mod << endl;
	return 0;
}
