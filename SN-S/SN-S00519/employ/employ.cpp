#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,mod=998244353;
int n,m;
int v[N],a[N],s[N];
int power(int a,int b){
	int ret=1;a%=mod;
	while(b){
		if(b&1)ret=ret*a%mod;b>>=1;a=a*a%mod;
	}
	return ret;
}
int fac[N],inv[N];
int C(int down,int up){
	if(up>down||up<0)return 0;
	return fac[down]*inv[up]%mod*inv[down-up]%mod;
}
int f[N][N][N];
signed main(){
	fac[0]=inv[0]=1;for(int i=1;i<=500;i++)fac[i]=fac[i-1]*i%mod,inv[i]=power(fac[i],mod-2);
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){char x;cin>>x;v[i]=x-'0';}
	for(int i=1;i<=n;i++){int x;cin>>x;a[x]++;}
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	if(n==m){
		int ans=1;
		for(int i=1;i<=n;i++)if(v[i]==0)ans=0;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans<<"\n";
		return 0;
	}
	bool p_all1=1;
	for(int i=1;i<=n;i++)if(!v[i])p_all1=0;
	if(p_all1){
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans<<"\n";
		return 0;
	}
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i;k++){
				if(v[i+1]==1){
					for(int p=0;p<=min(k,a[j+1]);p++){
						f[i+1][j+1][k-p]=(f[i+1][j+1][k-p]+f[i][j][k]*C(a[j+1],p)%mod*(s[j]-(i-k)))%mod;
					}
					f[i+1][j][k+1]=(f[i+1][j][k+1]+f[i][j][k])%mod;
				}
				else{
					for(int p=0;p<=min(k,a[j+1]);p++){
						f[i+1][j+1][k-p]=(f[i+1][j+1][k-p]+f[i][j][k]*C(a[j+1],p)%mod*(s[j]-(i-k)))%mod;
						f[i+1][j+1][k-p]=(f[i+1][j+1][k-p]+f[i][j][k]*C(a[j+1]-1,p)%mod*a[j+1])%mod;
					}
				}
				
			}
		}
	}
	int ans=0;
	for(int j=0;n-j>=m;j++){
		int w=fac[n-s[j]];
		for(int k=j+1;k<=n;k++)w=w*inv[a[k]]%mod;
		ans=(ans+f[n][j][n-s[j]]*w)%mod;
	}
	cout<<ans<<"\n";
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=n;j++){
//			for(int k=0;k<=n;k++){
//				cout<<f[i][j][k]<<" ";
//			}cout<<"\n";
//		}cout<<"\n";
//	}
	return 0;
}
/*
3 2
101
1 1 2

*/
