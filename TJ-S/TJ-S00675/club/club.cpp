#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int dp[205][205][205],n;
int a[N][3];
int tmp[N];
inline void o_solve(){
	bool flag2 = 1,flag1 = 1;
	for (int i = 1;i <= n;i++)
		if (a[i][2] != 0) flag2 = 0;
	for (int i = 1;i <= n;i++)
		if (a[i][1] != 0) flag1 = 0;
	if (flag1 == 1 && flag2 == 1){//特殊性质A
		int ans = 0;
		for (int i = 1;i <= n;i++) tmp[i] = a[i][0];
		sort(tmp + 1,tmp + n + 1);
		for (int i = n;i > n / 2;i--){
			ans += tmp[i];
		}
		printf("%lld",ans);
		return;
	}
}
inline void solve(){
	memset(dp,0,sizeof(dp));
	scanf("%lld",&n);
	for (int i = 1;i <= n;i++){
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
	}
	//进行DP
	if (n > 200){
		o_solve();
		return;
	}
	for (int k = 0;k < n;k++){
		for (int i = 0;i <= min(k,n / 2);i++){
			for (int j = 0;j <= min(k,min(n / 2,k - i));j++){
				if (i + 1 <= n / 2) dp[k + 1][i + 1][j] = max(dp[k + 1][i + 1][j],dp[k][i][j] + a[k + 1][0]);
				if (j + 1 <= n / 2) dp[k + 1][i][j + 1] = max(dp[k + 1][i][j + 1],dp[k][i][j] + a[k + 1][1]);
				if (k - i - j <= n / 2) dp[k + 1][i][j] = max(dp[k + 1][i][j],dp[k][i][j] + a[k + 1][2]);
			}
		}
	}
//	cout << "\n";
//	for (int k = 0;k <= n;k++){
//		for (int i = 0;i <= n / 2;i++){
//			for (int j = 0;j <= n / 2;j++){
//				cout << dp[k][i][j] << "  ";
//			}
//			cout << "\n";
//		}
//		cout << "\n\n";
//	}
	int ans = 0;
	for (int i = 0;i <= n / 2;i++){
		for (int j = 0;j <= n / 2;j++){
			if (n - i - j <= n / 2){
				ans = max(ans,dp[n][i][j]);
			}
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while (T--) solve();
return 0;
}
