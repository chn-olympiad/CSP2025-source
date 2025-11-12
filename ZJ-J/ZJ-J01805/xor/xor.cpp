#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=(1<<20)-1;
int n,k,a[N],dp[N];
int lst[M+100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=0;i<=M;i++) lst[i]=-1;
	lst[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		
		int t=a[i]^k;
		if(lst[t]!=-1)
			dp[i]=max(dp[i],dp[lst[t]]+1);//(lst_t+1,i)
		
		lst[a[i]]=i;
	}
	printf("%d",dp[n]);
	return 0;
}
