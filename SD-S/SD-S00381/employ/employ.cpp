#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,c[1005],t[1005],vis[1005];
int ans,m;
const int mod=998244353;
string a;
void check(){
	int cnt=0,now=0;
	for(int i=1;i<=n;++i){
		if(a[i]=='0'){
			++now;	
		}
		else{
			if(now>=c[t[i]]) ++now;
			else ++cnt;	
		}
	}
	ans+=(cnt>=m);
	if(ans>=mod) ans-=mod;
}
void dfs(int x){
	if(x==n+1){
		check();
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue ;
		vis[i]=1;
		t[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	a=' '+a;
	for(int i=1;i<=n;++i) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}

