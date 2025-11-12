#include<bits/stdc++.h>
#define ll long long
#define p 998244353
using namespace std;
ll n,m,k,x,a[510],s[510],fac[510],inv[510],f[262144][20],sm,ss,sa,ans;
string st;
ll qpow(ll x,ll y){ll ans=1;for(;y;x=x*x%p,y>>=1)if(y&1)ans=ans*x%p;return ans;}
ll C(ll x,ll y){return y<0||x<y?0:fac[x]*inv[y]%p*inv[x-y]%p;}
ll A(ll x,ll y){return y<0||x<y?0:fac[x]*inv[x-y]%p;}
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>st,st=" "+st,ss=fac[0]=f[0][0]=1;
	for(ll i=1;i<=n;i++)cin>>a[i],s[a[i]]++,k+=st[i]^48,fac[i]=fac[i-1]*i%p;
	inv[n]=qpow(fac[n],p-2);
	for(ll i=n;i;i--)inv[i-1]=inv[i]*i%p;
	if(m==n)cout<<(k==n&&s[0]==0)*fac[n],exit(0);
	else if(m==1){
		for(ll i=1;i<=n;i++){
			sm+=s[i-1];
			if(st[i]^48)sa++,ans=(ans+(n-sm)*fac[n-sa]%p*ss)%p,ss=ss*(sm-sa+1)%p;
		}
		cout<<ans,exit(0);
	}
	for(ll i=1;i<1<<n;i++){
		x=__builtin_popcount(i);
		for(ll j=0;j<=x;j++){
			for(ll k=1;k<=n;k++)if(i>>(k-1)&1){
				if(a[k]<=x-j-1||st[x]=='0')f[i][j]=(f[i][j]+f[i^1<<(k-1)][j])%p;
				if(a[k]>x-j&&st[x]=='1'&&j)f[i][j]=(f[i][j]+f[i^1<<(k-1)][j-1])%p;
			}
		}
	}
	for(ll i=m;i<=n;i++)ans=(ans+f[(1<<n)-1][i])%p;
	cout<<ans;
	return 0;
}
