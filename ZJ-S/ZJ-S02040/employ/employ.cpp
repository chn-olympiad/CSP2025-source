#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=600,mod=998244353;
ll n,m,c[N],ans;
string s;
bool vi[N],vis[N],able[N];
void dfs(ll v,ll ban){
	if(v>n){
		ll res=0;
		for(ll i=1;i<=n;i++){
			if(able[i]==1)res++;
		}
		if(res>=m){
			ans=(ans+1)%mod;	
		}
	}
	for(ll i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(!vi[v]||ban>=c[i]){
			able[i]=0;
			dfs(v+1,ban+1);
		}
		else{
			able[i]=1;
			dfs(v+1,ban);
		}
		vis[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(ll i=1;i<=n;i++){
		if(s[i-1]=='0')vi[i]=0;
		else vi[i]=1;
	}
	for(ll i=1;i<=n;i++)scanf("%d",&c[i]);
	dfs(1,0);
	cout<<ans;
	return 0;
}