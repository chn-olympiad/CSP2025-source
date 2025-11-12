#include<bits/stdc++.h>
#define N 505
#define ll long long
#define mod 998244353
using namespace std;
template<typename T> void read(T &x){
	x=0;int f=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) f=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	if(f) x=-x; 
}
int n,m;
int cnt[N],sum[N];
char s[N];
ll fac[N],inf[N];
ll qmi(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
	return ans;
}
ll C(int n,int m){
	return fac[n]*inf[m]%mod*inf[n-m]%mod;
}
ll f[2][N][N],tmp[N][N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	fac[0]=inf[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
		inf[i]=qmi(fac[i],mod-2);
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) {
		int x;
		read(x);
		cnt[x]++;
	}
	for(int i=n;i>=0;i--) sum[i]=sum[i+1]+cnt[i];
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		int c=i&1;
		memset(f[c],0,sizeof(f[c]));
		memset(tmp,0,sizeof(tmp));
		for(int j=0;j<i;j++){
			for(int k=0;k<=sum[i-j];k++){
				if(!f[c^1][j][k]) continue;
				if(s[i]=='1'&&k<sum[i-j]) f[c][j+1][k+1]=(f[c][j+1][k+1]+f[c^1][j][k])%mod;
				tmp[j][k]=(tmp[j][k]+f[c^1][j][k]*(n-sum[i-j]-(i-1)+k))%mod;
				if(s[i]=='0'&&k<sum[i-j]) tmp[j][k+1]=(tmp[j][k+1]+f[c^1][j][k])%mod;
			}
		}
		for(int j=0;j<=i;j++){
			for(int k=0;k<=sum[i-j];k++){
				if(!tmp[j][k]) continue;
				for(int l=0;l<=cnt[i-j]&&l<=k;l++){
					if(k-l>sum[i-j+1]) continue;
					f[c][j][k-l]=(f[c][j][k-l]+tmp[j][k]*fac[k]%mod*inf[k-l]%mod*C(cnt[i-j],l))%mod;
				}
			}
		}
	}
	ll ans=0;
	for(int i=m;i<=n;i++)
		for(int k=0;k<=sum[n-i+1];k++)
			if(f[n&1][i][k]) ans=(ans+f[n&1][i][k]*fac[k])%mod;
	cout<<ans;
	return 0;
}
