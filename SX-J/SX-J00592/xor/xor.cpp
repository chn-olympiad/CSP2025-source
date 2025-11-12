#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],id[2000005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
	for(int i=1;i<=(1<<20);i++) id[i]=-1;
	for(int i=1;i<=n;i++){
		int t=id[k^a[i]];
		dp[i]=dp[i-1];
		if(t!=-1) dp[i]=max(dp[i],dp[t]+1);
		id[a[i]]=i;
	}
	printf("%d\n",dp[n]);
	return 0;
}
