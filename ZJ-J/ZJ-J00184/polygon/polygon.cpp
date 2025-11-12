#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],ans;
void dfs(int i,int sum,int maxx){
	if(i>n){
		if(sum>maxx*2) ans=(ans+1)%mod;
		return;
	}
	dfs(i+1,sum,maxx);
	dfs(i+1,sum+a[i],max(maxx,a[i]));
	return;
}
signed main(){
	bool ts=1;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) ts=0;
	}
	if(ts){
		for(int i=3;i<=n;i++){
			int x=min(i,n-i);
			__int128 e=1;
			for(int j=1;j<=x;j++) e=(e*(n-j+1)/j);
			e%=mod;
			ans=(ans+e)%mod;
		}
	}else dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}

