#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=998244353;
ll n,a[5005],v[5005],ans;
void dfs(ll st,ll id,ll lim,ll mx,ll ls){
	if(id>=lim){
		if(st>2*mx)ans=(ans+1)%N;
		return;
	}
	for(int i=ls+1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(st+a[i],id+1,lim,max(mx,a[i]),i);
			v[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(0,0,i,-0x3f3f3f3f,0);
	}
	cout<<ans;
	return 0;
}
