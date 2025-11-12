#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5010],k=1;
long long ans,dp[5010][5010];
void dfs(int l,int cnt,int sum,int mx){
	if(l>n){
		if(cnt>=3&&sum>mx*2)
			ans++;
		return;
	}
	dfs(l+1,cnt,sum,mx);
	dfs(l+1,cnt+1,sum+a[l],max(mx,a[l]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)k=0;
	}
	if(k==1){
		dp[1][1]=1;
		for(int i=2;i<=n+1;i++)
			for(int j=1;j<=i;j++)
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		for(int i=4;i<=n+1;i++)
			ans+=dp[n+1][i],ans%=mod;
		printf("%lld",ans);
		return 0;
	}
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}
