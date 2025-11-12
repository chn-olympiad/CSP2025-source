#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],fac[5005],maxa,ans;
void dfs(int dep,int cnt,int sum,int maxx){
	if(dep==n+1){
		if(cnt<3) return;
		if(sum>2*maxx) ans++;
		return;
	}
	dfs(dep+1,cnt,sum,maxx);
	dfs(dep+1,cnt+1,sum+a[dep],max(maxx,a[dep]));
}
int ksm(int a,int b){
	int ans=1;
	while(b!=0){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m){
	return fac[n]*ksm(fac[m],mod-2)%mod*ksm(fac[n-m],mod-2)%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxa=max(maxa,a[i]);
	if(maxa==1){
		fac[0]=1;
		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
		for(int i=3;i<=n;i++) ans=(ans+C(n,i))%mod;
		cout<<ans<<'\n';
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<'\n';
	return 0;
}
