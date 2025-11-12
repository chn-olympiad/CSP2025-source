#include <bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N];
long long c[N][N],ans;
void dfs(int k,int ss,int s,int mx){
	if(k==n+1){
		if(ss>=3 && s>2*mx)ans=(ans+1)%mod;
		return;
	}
	dfs(k+1,ss+1,s+a[k],a[k]);
	dfs(k+1,ss,s,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int mx=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	if(mx==1){
		for(int i=1;i<=n;i++){
			c[i][0]=c[i][i]=1;
			for(int j=1;j<i;j++)
				c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
		for(int i=3;i<=n;i++)
			ans=(ans+c[n][i])%mod;
		printf("%lld\n",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	printf("%lld\n",ans);
	return 0;
}
