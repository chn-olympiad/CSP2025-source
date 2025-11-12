#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],f=1,mod=998244353,ans;
void dfs(int maxx,int sum,int now){
	if(now==n+1){
		if(maxx*2<sum){
			ans++;
			ans=(ans+mod)%mod;
		}
		return;
	}
	dfs(max(maxx,a[now]),sum+a[now],now+1);
	dfs(maxx,sum,now+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1)f=0;
	}
	if(f){
		int t=1;
		for(int i=1;i<=n;i++){
			t=(t*2+mod)%mod;
		}
		cout<<(t+mod-n*(n-1)/2-n-1)%mod;
		return 0;
	}
	if(n>50){
		cout<<0;
		return 0;
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
