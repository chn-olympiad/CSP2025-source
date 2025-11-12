#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=510,mod=998244353;
ll n,m,c[N],r,cmax,emin=N;
bool s[N],w[N],cheat=true;
char y[N];
void dfs(ll a,ll num,ll t){
	if(a>n){
		if(num>=m)
			r=(r+1)%mod;
		return;
	}
	if(num>=m){
		ll l=1;
		for(ll i=n-a+1;i>=1;i--)
			l=l*i%mod;
		r=(r+l)%mod;
		return;
	}
	if(n-a+1<m-num)
		return;
	for(ll i=1;i<=n;i++)
		if(!w[i]){
			w[i]=true;
			if(t>=c[i])
				dfs(a+1,num,t+1);
			else dfs(a+1,num+s[a],t+!s[a]);
			w[i]=false;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,y);
	for(ll i=0;i<n;i++){
		s[i+1]=y[i]-'0';
		cheat&=s[i+1];
		if(s[i+1])
			emin=min(emin,i+1);
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		cmax=max(cmax,c[i]);
	}
	if(cheat){
		ll l=1;
		for(ll i=1;i<=n;i++)
			l=l*i%mod;
		printf("%lld",l);
		return 0;
	}
	if(m==1){
		ll l=1;
		for(ll i=1;i<=n;i++)
			l=l*i%mod;
		if(cmax>=emin)
			printf("%lld",l);
		else printf("0");
		return 0;
	}
	if(m==n){
		ll l=1;
		for(ll i=1;i<=n;i++)
			l=l*i%mod;
		if(cheat)
			printf("%lld",l);
		else printf("0");
		return 0;
	}
	dfs(1,0,0);
	printf("%lld",r);
	return 0;
}
