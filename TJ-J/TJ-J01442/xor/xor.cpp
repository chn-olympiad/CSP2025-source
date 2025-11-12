#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,summ[500001],dp[500001],lst[2200001],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i = 1;i <= n;i++){
		scanf("%lld",&summ[i]);
		summ[i] ^= summ[i - 1];
	}
	lst[0] = 1;
	for (int i = 1;i <= n;i++){
		dp[i] = dp[i - 1];
		if (lst[k ^ summ[i]] != 0){
			dp[i] = max(dp[i],dp[lst[k ^ summ[i]] - 1] + 1);
		}
		ans = ((ans <  dp[i])?dp[i]:ans);
		lst[summ[i]] = i + 1;
	}
	printf("%lld",ans);
	return 0;
}
