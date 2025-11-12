#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline int read(){
	int s=0,k=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*k;
}

const int N=505,mod=998244353;
int n,m,sum[N],c[N];
char s[N];
ll C[N][N],f[N][N],fac[N],g[N][N],val[N][N];

ll Mod(ll x){return x>=mod?x-mod:x;}
void Add(ll &x,ll y){x=Mod(x+y);}

ll ksm(ll a,ll b){
	ll t=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1) t=t*a%mod;
	return t;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		int x=read();
		c[x]++;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	if(m==n){
		for(int i=1;i<=n;i++)
			if(s[i]=='0'){
				printf("0");
				return 0;
			}
		if(c[0]>0){
			printf("0");
			return 0;
		}
		printf("%lld",fac[n]);
		return 0;
	}
	for(int i=0;i<=n+1;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]);
	}
	for(int i=0;i<=n;i++) sum[i]=c[i];
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	for(int j=0;j<n;j++)
		for(int x=0;x<=c[j+1];x++) val[j][x]=C[c[j+1]][x]*fac[x]%mod;
	f[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i+1;j++)
			for(int k=0;k<=i+1;k++) g[j][k]=0;
		if(s[i+1]=='1'){
			for(int j=0;j<=i;j++)
				for(int k=0;k<=i;k++){
					Add(g[j][k+1],f[j][k]);
					int S=sum[j]-(i-k);
					if(S<=0) continue;
					for(int x=min(c[j+1],k);x>=0;x--)
						(g[j+1][k-x]+=f[j][k]*S%mod*C[k][x]%mod*val[j][x])%=mod;
				}
		}
		else{
			for(int j=0;j<=i;j++)
				for(int k=0;k<=i;k++){
					for(int x=min(c[j+1],k+1);x>=0;x--)
						(g[j+1][k+1-x]+=f[j][k]*C[k+1][x]%mod*val[j][x])%=mod;
					int S=sum[j]-(i-k);
					if(S<=0) continue;
					for(int x=min(c[j+1],k);x>=0;x--)
						(g[j+1][k-x]+=f[j][k]*S%mod*C[k][x]%mod*val[j][x])%=mod;
				}
		}
		for(int j=0;j<=i+1;j++)
			for(int k=0;k<=i+1;k++) f[j][k]=g[j][k];
	}
	ll ans=0;
	for(int j=0;j<=n-m;j++) (ans+=f[j][sum[n]-sum[j]]*fac[sum[n]-sum[j]])%=mod;
	printf("%lld",ans);
	return 0;
}

