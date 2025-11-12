#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=5e5+10;
const ll mod=998244353;
ll n,m,c[N],dp[N][20],ans,vis[N],a[N];
char s[N];
void dfs(ll x){
	if(x==n+1){
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=c[a[i]])cnt++;
		}
		if(n-cnt>=m)ans++;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			a[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);s[n+1]='9';
	for(ll i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	if(n<=10){
		dfs(1);
		printf("%lld\n",ans);
		return 0;
	}
	dp[0][0]=1;
	for(ll i=0;i<(1ll<<n);i++){
		ll cnt=0;
		for(ll k=1;k<=n;k++){
			if((i>>k-1)&1)cnt++;
		}		
		for(ll j=0;j<=cnt;j++){
			for(ll k=1;k<=n;k++){
				if((i>>k-1)&1)continue;
				ll f=(s[cnt+1]=='0'||j>=c[k]);
				dp[i+(1ll<<k-1)][j+f]=(dp[i+(1ll<<k-1)][j+f]+dp[i][j])%mod;
			}
		}
	}
	for(ll i=0;i<=n-m;i++){
		ans=(ans+dp[(1ll<<n)-1][i])%mod;
	}
	printf("%lld\n",ans);
	return 0;
} 
