#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,m,d[505],ans,ff[505];
char c;
bool hd[505],vis[505];
void dfs(int u,int f,int y){
	if(u==n+1){
		if(y>=m) ans=(ans+1)%MOD;
		return;
	}
	if(y==m){
		ans=(ans+ff[n-u+1])%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(f<d[i]&&!hd[u]){
			dfs(u+1,f,y+1);
		}
		else{
			dfs(u+1,f+1,y);
		}
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	ff[0]=1;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='0'){
			hd[i]=1;
		}
		ff[i]=(ff[i-1]*i)%MOD;
//		cout<<i<<' '<<ff[i]<<'\n';
	}
	for(int i=1;i<=m;i++){
		cin>>d[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
