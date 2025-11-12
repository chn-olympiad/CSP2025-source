#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1005;
ll opt[N];
ll shuzu[N];
ll n,m;
ll chs[N];
ll vis[11];
ll ans=0;
ll wt[N];
ll jueze=0;
const ll mod=998244353;
void dfs(ll x){
	if(x==n+1){
		ll pas=0;
		ll cnt=1;
		for(ll j=1;j<=n;j++){
			
			if(opt[j]==0||pas>=wt[chs[j]]){
				pas++;
			}
		}
		if(n-pas>=m){
			ans++;
		}
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			chs[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll cnt=1;
	for(ll i=1;i<=20;i++){
		shuzu[i]=cnt;
		cnt=cnt*2;
	}
	
	
	scanf("%lld%lld",&n,&m);
	string s;
	cin>>s;
	ll sz=s.size();
	s=" "+s;
	
	for(ll i=1;i<=sz;i++){
		if(s[i]=='1'){
			opt[i]=1;
		}
		else{
			opt[i]=0;
			jueze=1;
		}
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&wt[i]);
	}
	if(n<=10){
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
}
