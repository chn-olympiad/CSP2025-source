#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[505],cnt,vis[505],dp[600005][20],maxx;
string s;
int dfs(int pos,int shu,int ji){
	if(shu+n+1-pos<m) return 0;
	if(dp[ji][shu]) return dp[ji][shu];
	if(pos==n+1){
		return 1;
	}
	long long res=0;
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		if(pos-1-shu>=c[i] || s[pos-1]=='0') res+=dfs(pos+1,shu,ji+(1<<(i-1)));
		else res+=dfs(pos+1,shu+1,ji+(1<<(i-1)));
		res%=mod;
		vis[i]=0;
	}
	maxx=max(maxx,1ll*ji);
	return dp[ji][shu]=res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i) cin>>c[i];
	if(m==n){
		int flag=1;
		for(int i=1;i<=n;++i){
			if(s[i-1]=='0' || c[i]==0) flag=0;
		}
		if(flag){
			long long ans=1;
			for(int i=2;i<=n;++i) ans=ans*i%mod;
			cout<<ans;
		}
		else cout<<0;
		return 0;
	}
	cout<<dfs(1,0,0);
	return 0;
}
