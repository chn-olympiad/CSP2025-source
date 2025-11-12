#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=500+5;
const int maxm=(1<<18)+5;
const int mod=998244353;
int n,m;
string s;
int a[maxn];
ll dp[maxm][20];
int cnt[maxn],buc[maxn];
int fac[maxn],ifac[maxn];
int pw(int a,int x){int s=1;for(;x;x>>=1,a=1ll*a*a%mod)if(x&1)s=1ll*s*a%mod;return s;}
int calc(int n,int m){return n>=m&&m>=0?1ll*fac[n]*ifac[n-m]%mod:0;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		for(int i=0;i<n;i++) if(!(s[i]-'0')) return cout<<0<<'\n',0;
		for(int i=1;i<=n;i++) if(!a[i]) return cout<<0<<'\n',0;
		int ans=1;
		for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		fac[0]=1;
		for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
		ifac[n]=pw(fac[n],mod-2);
		for(int i=n-1;i>=0;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
		for(int i=0;i<n;i++){
			if(!(s[i]-'0')) cnt[n]++;
			else cnt[i]++;
		}
		// for(int i=0;i<=n;i++) cout<<cnt[i]<<' ';
		// cout<<'\n';
		for(int i=1;i<=n;i++) buc[a[i]]++;
		int tmp=1,tot=0;
		for(int i=n;i>=0;i--){
			tot+=cnt[i];
			if(tot<buc[i]){
				tmp=0;
				break;
			}
			// cout<<i<<' '<<tot<<' '<<buc[i]<<'\n';
			tmp=1ll*tmp*calc(tot,buc[i])%mod;
			tot-=buc[i];
		}
		int ans=1;
		for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
		cout<<(ans-tmp+mod)%mod<<'\n';
		return 0;
	}
	if(n<=18){
		for(int i=0;i<n;i++) a[i]=a[i+1];
		a[n]=0;
		dp[0][0]=1;
		for(int msk=1;msk<(1<<n);msk++){
			int x=__builtin_popcount(msk);
			for(int i=0;i<n;i++){
				if(!(msk&(1<<i))) continue;
				for(int j=0;j<x;j++){
					int t=j;
					if(x-1-j<a[i]&&s[x-1]-'0') t++;
					dp[msk][t]+=dp[msk^(1<<i)][j];
				}
			}
			for(int i=0;i<=x;i++) dp[msk][i]%=mod;
		}
		ll ans=0;
		for(int i=m;i<=n;i++) ans+=dp[(1<<n)-1][i];
		cout<<ans%mod<<'\n';
		return 0;
	}
	return 0;
}