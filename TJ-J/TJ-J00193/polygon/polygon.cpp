#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[5005],cnt[5005],ans = 0,dp[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1; i <= n;i++){
		scanf("%lld",&num[i]);
		cnt[i] = cnt[i - 1] + num[i];
 	}
	sort(num + 1,num + n + 1);
	dp[1] = cnt[1],dp[2] = cnt[2];
	for(int i = 3;i <= n;i++){
		int x = num[i] / 2;
		for(int j = 1;j <= i;j++){
			if(dp[j] > x){
				dp[i] = max(dp[i],num[i] + dp[j]);
				ans = (ans + 1) % 998244353;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
