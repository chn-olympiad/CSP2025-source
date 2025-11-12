#include<bits/stdc++.h>
#define ll long long
#define N 1001001
using namespace std;
ll n,k,a[N],pre[N],vis[N],cnt=0;
ll dfs(ll l){
	if(vis[l]!=0){
		return vis[l];
	}
	ll ans=0;
	for(ll len=0;len<=n-l;len++){
		for(ll i=l;i+len<=n;i++){
			if((pre[i-1]^pre[len+i])==k){
				ans=max(dfs(i+len+1)+1,ans);
			}
		}
	}
	vis[l]=ans;
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	dfs(1);
	cout<<vis[1];
	return 0;
}
