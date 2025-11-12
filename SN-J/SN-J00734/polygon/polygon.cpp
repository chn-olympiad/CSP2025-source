#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
const ll mod=998244353,MA=5010;
ll ans;
ll a[MA];
ll f[MA];
bool vis[MA];
void dfs(ll x,ll sum,ll maxn,ll y){
	if(sum>(2*maxn)&&x>3){
		ans++;
		ans%=mod;
	}
	if(x>n){
		return ;
	}
	for(ll i=y;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1,sum+a[i],max(maxn,a[i]),i); 
			vis[i]=0;
		} 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,INT_MIN,1);
	cout<<ans;
	return 0;
}

