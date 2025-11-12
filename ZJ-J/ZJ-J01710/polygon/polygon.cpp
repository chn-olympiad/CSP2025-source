#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5010];
ll ans;
void dfs(ll step,ll sum,ll mx,ll id){
	if(step>n){
		if(sum>mx*2)ans++;
		ans%=mod;
		return ;
	}
	dfs(step+1,sum+a[step],max(mx,a[step]),step);
	dfs(step+1,sum,mx,id);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f){
		ll ans=0;
		for(int i=3;i<=n;i++){
			ll t=i-2;
			ll num=(t+1)*t%mod/2;
			ans=(ans+num)%mod;
		}cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
//	for(ll i=1;i<=n;i++)cout<<i<<' '<<cnt[i]<<endl;
	return 0;
}