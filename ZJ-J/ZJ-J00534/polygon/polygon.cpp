#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
const int N=5010;
ll a[N],c[N],d[N];
ll n;
ll ans;
ll dfs(ll id,ll sum,ll maxx,ll cnt){
	if(id==n+1){
		if(sum>maxx*2&&cnt>2) ans=(ans+1)%MOD;
		return 0;
	}
	dfs(id+1,sum+a[id],max(maxx,a[id]),cnt+1);
	dfs(id+1,sum,maxx,cnt);
}
bool check(){
	for(int i=1;i<=n;i++) if(a[i]!=1) return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll flag=0;
	if(check()) flag=1;
	if(flag==1){
		if(n<3){
			cout<<0;
			return 0;
		}
		ll x=1;
		for(int i=1;i<=n;i++){
			x=x*2%MOD;
		}
		ll y=n*(n-1)/2%MOD;
		cout<<(x-n-y-1)%MOD;
		return 0;
	}
	if(n<=25){
		dfs(1,0,-1,0);
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
