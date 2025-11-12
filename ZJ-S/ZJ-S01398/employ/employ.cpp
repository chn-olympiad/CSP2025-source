#include<bits/stdc++.h>
#define pb push_back
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=105,mod=998244353;
int f[N][N][N],n,m,cnt[N],pre[N],C[N][N],fac[N],suf[N];
char s[N];
void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd();m=rd();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)cnt[rd()]++;
	for(int i=0;i<=n;i++)pre[i]=(i?pre[i-1]:0)+cnt[i];
	for(int i=n;~i;i--)suf[i]=suf[i+1]+cnt[i];
	for(int i=0;i<N;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++)
			for(int k=0;k<=i;k++){
				if(s[i+1]=='1'){
					add(f[i+1][j][k+1],f[i][j][k]);
					for(int l=0;l<=min(k,cnt[j+1]);l++){
						int sum=pre[j]-(i-k);
						if(sum>0)add(f[i+1][j+1][k-l],1ll*f[i][j][k]*C[cnt[j+1]][l]%mod*fac[l]%mod*sum%mod*C[k][l]%mod);
					}
					// if(i==2&&j==1&&k==2)cout<<f[i+1][j+1][k]<<' ' <<(pre[j]-(i-k))<<'\n';
				}else if(s[i+1]=='0'){
					for(int l=0;l<=min(k+1,cnt[j+1]);l++){
						int sum=pre[j]-(i-k);
						if(sum>0&&l<=k)add(f[i+1][j+1][k-l],1ll*f[i][j][k]*C[cnt[j+1]][l]%mod*fac[l]%mod*sum%mod*C[k][l]%mod);
						add(f[i+1][j+1][k+1-l],1ll*C[cnt[j+1]][l]%mod*fac[l]%mod*f[i][j][k]%mod*C[k+1][l]%mod);
						// cout<<i+1<<' '<<j+1<<' '<<k-l+1<<'\n';
					}
				}
			}
		// for(int j=0;j<=n;j++)
			// for(int k=0;k<=n;k++)if(f[i][j][k])cout<<i<<' '<<j<<' '<<k<<" "<<f[i][j][k]<<'\n';
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)
		for(int j=0;j<=n;j++)add(ans,1ll*f[n][i][j]*C[suf[i+1]][j]*fac[j]%mod);
	cout<<ans<<'\n';
	return 0;
}
/*
I will solve this problem.
*/