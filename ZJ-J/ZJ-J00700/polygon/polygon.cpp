#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
const int MOD=998244353;
const int INF=1e9;
int n,a[N],ans,mx,f[N][N];
void dfs(int dep,int s,int mx){
	if(dep==n+1){
		if(s<=mx*2)return;
		ans++;
		ans%=MOD;
		return;
	}
	dfs(dep+1,s+a[dep],max(mx,a[dep]));
	dfs(dep+1,s,mx);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
	if(mx<=1){
		for(int i=1;i<=n+1;i++){
			f[i][1]=i,f[i][i]=1;
			for(int j=2;j<i;j++){
				f[i][j]=(f[i-1][j]+f[i-1][j-1])%MOD;
			}
		}
		for(int i=3;i<=n;i++)ans=(ans+f[n][i])%MOD;
		cout<<ans;
		return;
	}
	dfs(1,0LL,0LL);
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
²Å320pts£¬ÒªAFOÁË55555555555 
*/
