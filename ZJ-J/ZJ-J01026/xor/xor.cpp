#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5,V=2e6+5;
int n,k;
int a[N],sum_xor[N],dp[N];
int lst[V];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(lst,-1,sizeof(lst));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	lst[0]=0;
	for(int i=1;i<=n;i++){
		int tmp=(a[i]^k^sum_xor[i-1]);
		if(lst[tmp]==-1) dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[lst[tmp]]+1);
		sum_xor[i]=(sum_xor[i-1]^a[i]);
		lst[sum_xor[i]]=i;
	}
	printf("%d",dp[n]);
	return 0;
}
