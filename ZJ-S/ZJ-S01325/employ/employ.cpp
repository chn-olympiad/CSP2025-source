#include<bits/stdc++.h>
using namespace std;
int n,m;
bool g[505];
int c[505];
const long long mod=998244353;
long long f[300005][21];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(!(ch>='0'&&ch<='1')) ch=getchar();
		g[i]=ch-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	f[0][0]=1;
	if(n<=18){
		for(int i=1;i<(1<<n);i++){
			int tg=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					tg++;
				}
			}
			for(int k=0;k<n;k++){
				if(i&(1<<k)){
					for(int j=0;j<=tg-1;j++){
						if(tg-1-j<c[k+1]&&g[tg]) f[i][j+1]=(f[i][j+1]+f[i^(1<<k)][j])%mod;
					}
					for(int j=0;j<=tg;j++){
						if(tg-1-j>=c[k+1]||g[tg]==0) f[i][j]=(f[i][j]+f[i^(1<<k)][j])%mod;
					}
				}
			}
		}
		long long ans=0;
		for(int i=m;i<=n;i++){
			ans+=f[(1<<n)-1][i];
			ans%=mod;
		}
		printf("%lld",ans);
	}
	else{
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		printf("%lld",ans);
	}
	return 0;
}
