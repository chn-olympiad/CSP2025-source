#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+10,mod=998244353;
ll n,m,c[N],ans,sum,vis[N],cc[N];
bool f=true;
string s;
void dfs(ll id){
	if(id==n+1){
		ll dele=0,ok=0;
		for(ll i=1;i<=n;i++){
			if(dele>=cc[i] or s[i]=='0') dele++;
			else ok++;
		}
		if(ok<m) return ;
		ans++;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		cc[id]=c[i];
		dfs(id+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;s="*"+s;
	for(ll i=1;i<=n;i++){
		if(s[i]=='0') f=false;
	}
	for(ll i=1;i<=n;i++) scanf("%lld",&c[i]),sum+=(c[i]!=0);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
