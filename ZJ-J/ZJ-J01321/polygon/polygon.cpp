#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int i,j,ans,cnt,n,a[5010],f[5010][5010];
void dfs(int t,int s,int ma){
	if(t>n){
		if(s>2*ma)ans=(ans+1)%mod;
		return ;
	}
	dfs(t+1,s,ma);
	dfs(t+1,s+a[t],max(ma,a[t]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(i=0;i<=5000;i++)f[i][0]=1;
	for(i=1;i<=5000;i++)
		for(j=1;j<=i;j++)
			f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],cnt+=(a[i]==1);
	if(cnt==n){
		for(i=3;i<=n;i++)
			ans=(ans+f[n][i])%mod;
		cout<<ans;
	}
	else{
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}
