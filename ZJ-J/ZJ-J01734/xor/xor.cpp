#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=5e6+5;
int n,m,a[N],sum[N],dp[N],mp[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(mp,-1,sizeof(mp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}mp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],mp[m^sum[i]]+1);
		mp[sum[i]]=dp[i];
	}printf("%d",dp[n]);
	return 0;
}
