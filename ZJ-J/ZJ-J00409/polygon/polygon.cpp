#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+7,mod=998244353;
int n,a[maxn],ans,vis[maxn];
long long fac[maxn],inv[maxn];
void dfs(int d,int mx,int sum,int bg){
	if(d>2){
		if(sum>a[mx]) ans++,ans%=mod;
	}
	if(d>mx) return;
	for(register int i=bg;i<mx;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(d+1,mx,sum+a[i],i+1);
			vis[i]=0;
		}
	}
}
void init(){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(register int i=2;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for(register int i=2;i<=n;i++) inv[i]=(mod-mod/i)%mod*inv[mod%i]%mod;
	for(register int i=2;i<=n;i++) inv[i]=inv[i-1]%mod*inv[i]%mod;
}
long long cal(int n,int m){
	return fac[n]%mod*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	init();
	bool flag=1;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		for(register int i=3;i<=n;i++){
			ans+=cal(n,i)%mod;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(register int i=3;i<=n;i++){
		dfs(1,i,0,1);
	}
	cout<<ans;
	return 0;
}
