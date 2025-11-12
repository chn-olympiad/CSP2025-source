#include<bits/stdc++.h>
#define int long 

using namespace std;

const int N=5010,mod=998244353;

int n,a[N],ans;

void dfs(int idx,int maxx,int sum,int gs){
	if(idx==n+1){
		if(maxx*2<sum&&gs>=3) ans=(ans+1)%mod;
		return;
	}
	dfs(idx+1,maxx,sum,gs);
	dfs(idx+1,maxx=max(maxx,a[idx]),sum+a[idx],gs+1);
	return;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	freopen("polygon.in","r",stdin); freopen("polygon.out","w",stdout);
 	int maxxx=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) maxxx=max(maxxx,a[i]);
	if(maxxx==1){
		cout<<n-2<<"\n";
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<"\n";
	return 0;
}
