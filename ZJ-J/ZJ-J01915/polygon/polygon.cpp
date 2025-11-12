#include<bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5005][5005],s[5005],ans,qpow[5005];
const int mod=998244353;
int dfs(int x,int y){
	if(y<0)return qpow[x];
	if(x<=0||y>s[x])return 0;
	if(dp[x][y])return dp[x][y];
	return dp[x][y]=(dfs(x-1,y)+dfs(x-1,y-a[x]))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n;qpow[0]=1;
	for(int i=1;i<=5000;i++){
		qpow[i]=qpow[i-1]*2%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		ans+=(i>=3?dfs(i-1,a[i]):0);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
