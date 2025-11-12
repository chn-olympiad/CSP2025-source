#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
const int N=505;
ll n,m,c[N],vis[N],sum[N],fac[N],pp[N],finv[N],ans=0,plp=0,gg=0;
string s;
void dfs(int x,ll summ){
	if(x>n){
		if(summ>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if((s[x]-'0')==1&&plp<c[i]){
				dfs(x+1,summ+1);
			}else{
				plp++;
				dfs(x+1,summ);
				plp--;
			}
			vis[i]=0;
		}
	}
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
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	bool flag=true;
	cin>>n>>m;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) gg++;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0') flag=false;
		sum[i]=sum[i-1]+(s[i]=='0');
	}
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<' ';
//	}
//	cout<<'\n';
	if(n<=10){
		dfs(1,0);
		cout<<ans;
	}else if(flag){
		fac[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=fac[i-1]*i%mod;
		}
		finv[n]=qpow(fac[n],mod-2,mod);
		for(int i=n-1;i>=0;i--){
			finv[i]=finv[i+1]*(i+1)%mod;
		}
		for(int i=1;i<=n;i++){
			if(c[i]) pp[min(gg,c[i]-1)]++;
		}
		for(int i=m;i<=n-gg;i++){
			ans=(ans+fac[i]*gg%mod*fac[n-i-1]%mod)%mod;
		}
		cout<<ans;
	}
	return 0;
}
