#include<bits/stdc++.h>
typedef long long ll;
const ll N=550;
const ll mod=998244353;
using namespace std;
ll n,m,a[N],c[N],ans;
bool vis[N];
char s[N];
void dfs(ll cnt){
	if(cnt==n+1){
		ll nw=0;
		for(ll i=1;i<=n;i++){
			if(a[c[i]]<=nw){
				nw++;
				continue;
			}
			if(s[i]=='0')
				nw++;
		}
		if(n-nw>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			c[cnt]=i;
			dfs(cnt+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
