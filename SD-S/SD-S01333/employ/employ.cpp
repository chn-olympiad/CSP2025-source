#include<bits/stdc++.h>
#define ll long long
const ll N=1010;
const ll mod=998244353;
using namespace std;
ll n,m,ans;
char s[N];
ll c[N],vis[N],p[N];
void dfs(ll cnt,ll sum){
	if(n-sum+n-cnt+1<m)return;
	if(cnt==n+1){
		if(n-sum>=m){
			ans++;
		}
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		p[cnt]=i;
		if(sum<=c[i]){
			if(s[cnt]=='0')dfs(cnt+1,sum+1);
			else dfs(cnt+1,sum);
		}
		else{
			dfs(cnt+1,sum+1);
		}
		vis[i]=0;
	}
}
ll fac[N];
void Solve(){
	fac[0]=1;
	for(ll i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	printf("%lld",fac[n]);
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	ll flag=0;
	for(ll i=1;i<=n;i++){
		if(s[i]=='0'){
			flag=1;
			break;
		}
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	if(!flag){
		Solve();
		return 0;
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
} 
