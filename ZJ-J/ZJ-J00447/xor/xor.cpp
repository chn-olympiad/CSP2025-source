#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],dp[N],g[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i]=-1e9;
		g[i]=-1;
	}
	for(int i=1;i<=n;i++){
		int s=a[i];
		if(s==k) g[i]=max(g[i],i);
		for(int j=i+1;j<=n;j++){
			s^=a[j];
			if(s==k){
				g[j]=max(g[j],i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(g[i]<0){
			dp[i]=dp[i-1];
			continue;
		}
		for(int j=0;j<g[i];j++){
			dp[i]=max(dp[i],dp[j]+1);
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}

