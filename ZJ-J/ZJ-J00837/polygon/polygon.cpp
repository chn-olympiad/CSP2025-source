#include <bits/stdc++.h>
using namespace std;
int n,i,ans,a[5010];
int f[5010][5010];
const int mod=998244353;
void dfs(int t,int s,int ma){
	if(t>n){
		if(s>ma*2) ans++;
		return ;
	}
	dfs(t+1,s+a[t],max(ma,a[t]));
	dfs(t+1,s,ma);
}
void ts(){
	int i,j;
	ans=0;
	for(i=1;i<=5000;i++) f[i][1]=i;
	for(i=2;i<=5000;i++)
		for(j=2;j<=i;j++)
			f[i][j]=f[i-1][j]+f[i-1][j-1],f[i][j]%=mod;
	for(i=3;i<=n;i++) ans+=f[n][i],ans%=mod;
	cout<<ans;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i],ans+=a[i];
	ans=0;
	if(ans==n){
		ts();
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
