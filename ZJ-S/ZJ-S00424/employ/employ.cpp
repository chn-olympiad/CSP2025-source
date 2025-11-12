#include<bits/stdc++.h>
#define N 505
using namespace std;
const int mod=998244353;
int jie[N];
int C[N][N];
char s[N];
int tong[N];
int qian[N];
int g[N];
int dp[2][N][N];
inline void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jie[0]=1;for(int i=1;i<=500;i++)jie[i]=1ll*jie[i-1]*i%mod;
	C[0][0]=1;
	for(int i=1;i<=500;i++){
		C[i][0]=1;
		for(int j=1;j<=500;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	int n,m;scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		tong[x]++;
	}
	qian[0]=tong[0];
	for(int i=1;i<=n;i++)qian[i]=tong[i]+qian[i-1];
	int now=0;
	dp[now][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				dp[now^1][j][k]=0;
			}
		}
		for(int j=0;j<=i-1;j++){
			for(int k=0;k<=i-1;k++){
				if(dp[now][j][k]==0)continue;
//				printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
				for(int l=0;l<=min(k,tong[i-j]);l++){
					int sheng=qian[i-j-1]-(i-1-k);
					if(sheng<=0)continue;
					add(dp[now^1][j][k-l],1ll*dp[now][j][k]*
					C[k][l]%mod*C[tong[i-j]][l]*jie[l]%mod*
					sheng%mod);
				}
				if(s[i]=='0'){
					for(int l=0;l<=min(k+1,tong[i-j]);l++){
						add(dp[now^1][j][k-l+1],1ll*dp[now][j][k]*
						C[k+1][l]%mod*C[tong[i-j]][l]%mod*jie[l]%mod);
					}
				}
				else {
					add(dp[now^1][j+1][k+1],dp[now][j][k]);
				}
			}
		}
		now^=1;
	}
	int ans=0;
	for(int daan=m;daan<=n;daan++){
		for(int sheng=0;sheng<=n;sheng++){
			int zhi=dp[now][daan][sheng];
			int haiyou=n-qian[n-daan];
			if(haiyou==sheng)ans=(ans+1ll*zhi*jie[sheng]%mod)%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
3 2
101
1 1 2
*/