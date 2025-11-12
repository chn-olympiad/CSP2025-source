#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f=1,c[505],s[505],vis[505],wtt,ans;
void dfs(int x,int tu,int ok){
	if(x==n+1){
		if(ok>=m)ans=(ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		else if(c[i]<=tu||!s[x])vis[i]=1,dfs(x+1,tu+1,ok);
		else vis[i]=1,dfs(x+1,tu,ok+1);
		vis[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		s[i]=ch-'0';
		f&=s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];wtt+=(c[i]==0);
	}
	if(m==n&&f&&!wtt){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}
		cout<<ans<<'\n';
	}
	else if(m==n){
		cout<<0;
	}
	else{
		dfs(1,0,0);
		cout<<ans;
	}
	return 0;
}