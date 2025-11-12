#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
const int N=5005;
ll n,a[N],ans=0,fac[N],finv[N],summ,dp[600005];
void dfs(int x,ll sum,ll maxn){
	if(x>n){
		if(sum>2*maxn) ans=(ans+1)%mod;
		return ;
	}
	dfs(x+1,sum,maxn);
	dfs(x+1,sum+a[x],max(maxn,a[x]));
}
inline bool cmp(ll x,ll y){
	return x>y;
}
inline ll qpow(ll a,ll b,ll p){
	ll res=1;
	while(b){
		if(b&1){
			res=res*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return res;
}
inline ll C(ll n,ll m){
	if(n<m) return 0;
	if(m==0) return 1;
	return fac[n]*finv[m]%mod*finv[n-m]%mod;
}
void init(int n){
	fac[0]=1;
	for(ll i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	finv[n]=qpow(fac[n],mod-2,mod);
	for(ll i=n-1;i>=0;i--){
		finv[i]=finv[i+1]*(i+1)%mod;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
	}else if(n<=500){
		sort(a+1,a+n+1);
		dp[0]=1;
		for(int i=1;i<=n;i++){
			summ+=a[i];
			for(int j=summ;j>=a[i];j--){
				dp[j]=(dp[j]+dp[j-a[i]])%mod;
			}
			if(i<n){
				for(int j=summ;j>a[i+1];j--){
					ans=(ans+dp[j])%mod;
				}
			}
			
		}
		cout<<ans;
	}else if(flag){
		init(n);
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%mod;
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
