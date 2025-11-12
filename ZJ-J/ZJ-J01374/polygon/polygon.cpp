#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5005],ans=0;
void dfs(ll x,ll cnt,ll sum,ll mx){
	if(x>n){
		if(sum>mx*2&&cnt>=3){
			ans++;
			ans=(ans+mod)%mod;
		}
		return;
	}
	dfs(x+1,cnt+1,sum+a[x],max(mx,a[x]));
	dfs(x+1,cnt,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans<<"\n";
	return 0;
}