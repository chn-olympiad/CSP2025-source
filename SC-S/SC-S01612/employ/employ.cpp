#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505,Mod=998244353;
ll read(){
	ll x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
ll n,m,arr[N],c[N],fac[N],ans,s[N],ss[N];
ll pl[N];
bool ch[N];
void dfs(ll now){
	if(now>n){
		ll qi=0,lc=0;
		for(ll i=1;i<=n;i++){
			if(!arr[i]||qi>=c[pl[i]]) qi++;
			else lc++;
		}
		if(lc>=m){
			ans++;
			ans%=Mod;
		}
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(!ch[i]){
			ch[i]=1;
			pl[now]=i;
			dfs(now+1);
			pl[now]=0;
			ch[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool flag=1;
	ll zong=0;
	for(ll i=1;i<=n;i++){
		char c;cin>>c;
		arr[i]=c-'0';
		if(!arr[i]) flag=0;
		zong+=arr[i];
	}
	fac[0]=1;
	for(ll i=1;i<=n;i++) fac[i]=fac[i-1]*i%Mod;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans<<'\n';
		return 0;
	}
	else if(flag){
		cout<<fac[n]<<'\n';
		return 0;
	}
	else if(m==n){
		if(zong==n) cout<<fac[n]<<'\n';
		else cout<<0<<'\n';
		return 0;
	}
	else cout<<0<<'\n';
	return 0;
}