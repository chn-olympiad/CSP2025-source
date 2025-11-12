#include<bits/stdc++.h>
using namespace std;
const int N=509,mod=998244353;
int n,m,c[N],p[N],fac[N],invf[N];string s;
int C(int n,int m){return 1ll*fac[n]*invf[n-m]%mod*invf[m]%mod;}
int qpow(int a,int b){int ret=1;for(;b;a=1ll*a*a%mod,b>>=1)if(b&1)ret=1ll*ret*a%mod;return ret;}
int main(){freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=500;i++)fac[i]=1ll*fac[i-1]*i%mod;
	invf[500]=qpow(fac[500],mod-2);
	for(int i=499;~i;i--)invf[i]=1ll*invf[i+1]*(i+1)%mod;
	cin>>n>>m>>s;int flg=1;
	for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
	for(int i=0;i<n;i++)if(s[i]=='0')flg=0;
	if(n<=10){
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='0')++cnt;
				else if(c[p[i]]<=cnt)++cnt;
			}if(n-cnt>=m)++ans;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}else if(flg){
		
	}else if(m==1){
		int pos=-1,cnt=0;
		for(int i=0;i<n;i++)if(s[i]=='1'){pos=i;break;}
		for(int i=1;i<=n;i++)if(c[i]>pos)++cnt;
		int ans=0;
		for(int i=1;i<=cnt;i++)ans=(ans+1ll*C(n,i)*C(pos,i-1)%mod*fac[pos-i+1]%mod)%mod;
		cout<<1ll*ans*fac[n-pos-1]%mod;
	}else if(m==n){
		cout<<0;
	}else{
		
	}
	return 0;
}
