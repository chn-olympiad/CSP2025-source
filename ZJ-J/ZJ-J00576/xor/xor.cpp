#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50,M=1<<21;
int s[N],n,k,a[N],lst[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(lst,-1,sizeof lst);
	lst[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		if(lst[s[i]^k]==-1)dp[i]=dp[i-1];
		else dp[i]=max(dp[lst[s[i]^k]]+1,dp[i-1]);
		lst[s[i]]=i;
	}
	printf("%d",dp[n]);
	return 0;
}

