#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5,MOD=998244353;
char s[N];
int n,m,c[N],S[N],f[N][N],T[N][N],g[N][N],fr[N],inv[N];
int power(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}
int C(int x,int y){
	if(x<y) return 0;
	return fr[x]*inv[y]%MOD*inv[x-y]%MOD;
}
signed main(){
//	system("fc club.out club5.ans");
//	cout<<sizeof(f);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fr[0]=1;
	for(int i=1;i<N;i++) fr[i]=fr[i-1]*i%MOD;
	inv[N-1]=power(fr[N-1],MOD-2);
	for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%MOD;
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		int x;scanf("%lld",&x);
		c[x]++;
	}
	S[0]=c[0];
	for(int i=1;i<=n;i++) S[i]=S[i-1]+c[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++)
			for(int k=0;k<=n;k++) T[j][k]=g[j][k]=0;
		if(s[i]=='0'){
			for(int j=0;j<=i;j++){
				for(int k=0;k<=n;k++){
					if(S[j]>=k) g[j+1][k+1]=(g[j+1][k+1]+f[j][k]*(S[j]-k))%MOD;//choose one,c_t<=j
					g[j+1][k]=(g[j+1][k]+f[j][k])%MOD;
				}
			}
			for(int j=0;j<=i;j++){
				for(int k=n;k>=0;k--){
					for(int t=max(0ll,i-k-n+S[j]);t<=c[j];t++)
						T[j][k+t]=(T[j][k+t]+g[j][k]*C(i-k,t)%MOD*C(c[j],t)%MOD*fr[t])%MOD;
				}
			}
			for(int j=0;j<=i;j++)
				for(int k=0;k<=n;k++) f[j][k]=T[j][k];
		}else{
			for(int j=0;j<=i;j++){
				for(int k=0;k<=n;k++){
					if(S[j]>=k) g[j+1][k+1]=(g[j+1][k+1]+f[j][k]*(S[j]-k))%MOD;//choose one,c_t<=j
				}
			}
			for(int j=0;j<=i;j++){
				for(int k=n;k>=0;k--){
					for(int t=max(0ll,i-k-n+S[j]);t<=c[j];t++)
						T[j][k+t]=(T[j][k+t]+g[j][k]*C(i-k,t)%MOD*C(c[j],t)%MOD*fr[t])%MOD;
				}
			}
			for(int j=0;j<=i;j++)
				for(int k=0;k<=n;k++) g[j][k]=T[j][k];
			for(int j=0;j<=i;j++){
				for(int k=0;k<=n;k++){
					g[j][k]=(g[j][k]+f[j][k])%MOD;
				}
			}
			for(int j=0;j<=i;j++)
				for(int k=0;k<=n;k++) f[j][k]=g[j][k];
		}
//		for(int j=0;j<=n;j++){
//			for(int k=0;k<=n;k++) cout<<f[i][j][k]<<' ';
//			cout<<'\n';
//		}
//		cout<<'\n';
	}
	int ans=0;
	for(int j=0;j<=n;j++)
		for(int k=0;k<=n;k++) if(j<=n-m && n-S[j]>=n-k) ans=(ans+f[j][k]*fr[n-k])%MOD;
	printf("%lld",ans);
	return 0;
}
//17:04
