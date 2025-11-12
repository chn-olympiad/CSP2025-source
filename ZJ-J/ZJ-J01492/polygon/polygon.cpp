#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
ll n,a[5005],c,ans,tag,vis[5005];
void dfs(ll i,ll cnt,ll sum,ll maxx){
	if(i==n+1){
		if(cnt>=3)ans=(ans+(sum>2*maxx))%MOD;
		return;
	}
	dfs(i+1,cnt,sum,maxx);
	dfs(i+1,cnt+1,sum+a[i],a[i]);
}
ll gcd(ll x,ll y){
	while(x%y!=0){
		ll r=x%y;
		x=y;
		y=r;
	}
	return y;
}
ll suan(ll n,ll m){
	ll ans=1;
	for(ll i=1;i<=m;i++)vis[i]=i;
	for(ll i=n-m+1;i<=n;i++){
		ll ts=i;
		for(ll j=1;j<=m;j++){
			ll x=gcd(ts,vis[j]);
			vis[j]/=x;
			ts/=x;
		}
		ans=ans*ts%MOD;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)tag=1;
	}
	sort(a+1,a+1+n);
	if(tag==0){
		for(ll i=3;i<=n;i++){
			ans=(ans+suan(n,i))%MOD;
			memset(vis,0,sizeof vis);
		}
		cout<<ans;
	}else{
		dfs(1,1,0,0);
		cout<<ans;
	}
	return 0;
}
