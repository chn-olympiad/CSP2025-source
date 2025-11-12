#include<bits/stdc++.h>
#define lon long long
using namespace std;
const lon mod=998244353;
int n,m;//500
char s[510];
int c[510];
lon jc[510];
lon ans;
bool vis[510];
bool qwq;
void dfs(int w,int tt,int gs){
	if(gs>=m){
		ans=(ans+jc[n-w])%mod;
		return ;
	}
	if(n-w+gs<m) return ;
	for(int i=1;i<=n;i++) if(!vis[i]){
		vis[i]=1;
		qwq=(s[w+1]=='0') || (tt>=c[i]);
		dfs(w+1,tt+qwq,gs+!qwq);
		vis[i]=0;
	}
	return ;
}
void init(){
	jc[0]=1;
	jc[1]=1;
	for(int i=2;i<=n;i++) jc[i]=(jc[i-1]*(lon)i)%mod;
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	init();
	cin>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
