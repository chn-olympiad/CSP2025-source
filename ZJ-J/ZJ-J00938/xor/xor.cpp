#include<bits/stdc++.h>
using namespace std;
int dp[500005],sum[500005];
int p[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(p,-1,sizeof(p));
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		sum[i]=sum[i-1]^x;
	}
	p[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int v=k^sum[i];
		if(p[v]!=-1)dp[i]=max(dp[i],dp[p[v]]+1);
		p[sum[i]]=i;
	}
	printf("%d\n",dp[n]);
	
}
