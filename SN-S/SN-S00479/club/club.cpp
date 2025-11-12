#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MA=1e5+10;
ll a[MA],b[MA],c[MA];
ll ans=INT_MIN;
ll n,t;
void dfs(ll x,ll y,ll z,ll sum,ll id){
	if(x>t||y>t||z>t){
		return ;
	}
	if(id>n){
		ans=max(ans,sum);
		return ;
	}
	dfs(x+1,y,z,sum+a[id],id+1);
	dfs(x,y+1,z,sum+b[id],id+1);
	dfs(x,y,z+1,sum+c[id],id+1); 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		cin>>n;
		t=n/2;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		ans=INT_MIN;
		dfs(1,0,0,a[1],2);
		dfs(0,1,0,b[1],2);
		dfs(0,0,1,c[1],2);
		cout<<ans<<endl;
	}
	return 0;
}
