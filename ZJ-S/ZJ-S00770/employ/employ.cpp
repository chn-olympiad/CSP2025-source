//long long
//mod
#include<bits/stdc++.h>
using namespace std;
const long long N=505,mod=998244353;
bool b[N];
long long n,m,ans,c[N];
bool vis[N];
void dfs(long long id,long long bye){
	if(n-bye<m)return;
	if(id==n+1){
		ans=(ans+1)%mod;
		return;
	}
	for(long long i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(bye>=c[i]||b[id]==0)dfs(id+1,bye+1);
		else dfs(id+1,bye);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		char p;
		cin>>p;
		b[i]=p-'0';
	}
	for(long long i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
