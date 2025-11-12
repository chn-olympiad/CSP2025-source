#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=505;
int f[2][N][N];
char s[N];
int tot[N],tc[N];
int c[N];
int fac[N],inv[N];
int C(int n,int m){
	if(n<0||m<0||n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<N;i++){
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=2;i<N;i++){
		inv[i]=inv[i]*inv[i-1]%mod;
	}
	int n,m;
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	int kp=0;
	for(int i=1;i<=n;i++)if(s[i]=='0')kp++;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		tot[c[i]]++;
	}
	if(kp==0){
		printf("%lld\n",fac[n]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		tc[i]=tc[i-1]+tot[i];
	}
	f[0][0][0]=1;
	int ls=0,ne=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=tc[j];k++){
			//	f[i-1][j][k]->
				if(s[i]=='0'){
					for(int p=k;p<=k+tot[j+1]+1&&p<=tc[j+1];p++){
//						if(p==j){
//							f[i][j+1][p]=(f[i][j+1][p]+f[i-1][j][k])%mod;
//						}
//						else 
					//	f[i][j+1][p]=(f[i][j+1][p]+f[i-1][j][k]*C(i-k-1,p-k)%mod*fac[tot[j+1]]%mod*inv[tot[j+1]-p+k]%mod);
					//	f[i][j+1][p]=(f[i][j+1][p]+f[i-1][j][k]*C(i-1-k,p-k-1)%mod*fac[tot[j+1]]%mod*inv[tot[j+1]-p+k+1]%mod*(tc[j+1]-p+1)%mod)%mod;
						f[ne][j+1][p]=(f[ne][j+1][p]+f[ls][j][k]*C(i-1-k,p-k)%mod+f[ls][j][k]*C(i-1-k,p-k-1)%mod*(tc[j+1]-(p-1))%mod)%mod;
					}
				}
				if(s[i]=='1'){
					f[ne][j][k]=(f[ne][j][k]+f[ls][j][k])%mod;
					for(int p=k+1;p<=k+1+tot[j+1];p++){
						f[ne][j+1][p]=(f[ne][j+1][p]+f[ls][j][k]*C(i-1-k,p-k-1)/*fac[tot[j+1]]%mod*inv[tot[j+1]-p+k+1]*/%mod*(tc[j]-k)%mod)%mod;
					}
				}
			}
		}
		swap(ls,ne);
		memset(f[ne],0,sizeof(f[ne]));
	}
	int ans=0;
	for(int j=0;j<=n;j++){
		if(n-j>=m)
		{
			int mul=1;
			for(int p=0;p<=j;p++)mul=mul*fac[tot[p]]%mod;
			ans=(ans+f[ls][j][tc[j]]*fac[(tc[n]-tc[j])]%mod*mul%mod)%mod;
		}
	}
//	for(int i=0;i<=n;i++)ans=ans*fac[tot[i]]%mod;
//	for(int i=1;i<=n;i++)ans=ans%mod;
	printf("%lld",ans);
	return 0;
}
