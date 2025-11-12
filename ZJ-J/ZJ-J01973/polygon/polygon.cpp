#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,mod=998244353;
int n,a[N],ans,vis[N],mx;
void dfs(int now, int sum, int maxx, int got){
	if(now>n){
		if(got>=3&&sum>maxx*2) ans=(ans+1)%mod;
		return;
	}
	dfs(now+1,sum,maxx,got);
	dfs(now+1,sum+a[now],max(maxx,a[now]),got+1);
}
int fac(int n){
	int ret=1;
	for(int i=2;i<=n;i++){
		ret=ret*i%mod;
	}
	return ret;
}
int ksm(int a, int b){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int inv(int n){
	return ksm(n,mod-2);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx!=1){
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}else{ // all of them are 1
		for(int i=3;i<=n;i++){
			int now=fac(n)*inv(fac(i))%mod;
			now=now*inv(fac(n-i))%mod;
			ans=(ans+now)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
