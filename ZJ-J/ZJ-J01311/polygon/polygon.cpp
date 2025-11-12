#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
ll n,a[5010],f[5010],ans;
void dfs(ll sum,ll maxx,ll m,ll s){	
	if(s>n)return;
	if(sum+a[s]>max(maxx,a[s])*2&&m+1>=3)ans++;
	dfs(sum+a[s],max(maxx,a[s]),m+1,s+1);
	dfs(sum,maxx,m,s+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<ans%mod;
}