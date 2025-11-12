#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using i128=__int128;
using ull=unsigned long long;
//bool f1;
inline void read(int &a){
	a=0;register char c=getchar();bool ff=0;
	while(c<'0'||'9'<c){if(c=='-') ff=1;c=getchar();}
	while('0'<=c&&c<='9'){a=(a<<3)+(a<<1)+(c^48);c=getchar();}
	if(ff) a=-a;
}
namespace SOLVE{
	const int N=505,mod=998244353;
	int n,m,t[N],p[N],tsum[N];
	ll C[N][N],jc[N];
	ll f[N][N],g[N][N];
	void add(ll &a,ll b){
		a+=b;
		if(a>=mod) a-=mod;
	}
	void main(){
		read(n);read(m);
		for(int i=1,cc;i<=n;i++){
			cc=getchar();
			while(cc!='0'&&cc!='1') cc=getchar();
			p[i]=cc-'0';
		}
		for(int i=1,cc;i<=n;i++){
			read(cc);
			t[cc]++;
		}
		for(int i=0;i<=n;i++){
			C[i][0]=1;
			for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
		jc[0]=1;
		for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
		tsum[0]=t[0];
		for(int i=1;i<=n;i++) tsum[i]=tsum[i-1]+t[i];
		f[0][t[0]]=1;
		for(int i=1;i<=n;i++){
			if(p[i]==0){
				for(int j=0;j<=n;j++) for(int k=tsum[j]-i+1;k<=tsum[j];k++) if(f[j][k]) for(int a=0;a<=t[j+1];a++){
					ll w=C[t[j+1]][a]*jc[a]%mod;
					if(k+a) add(g[j+1][k+t[j+1]-a-1],f[j][k]*C[i-(tsum[j]-k)-1][a]%mod*k%mod*w%mod);//<=j
					if(a) add(g[j+1][k+t[j+1]-a],f[j][k]*C[i-(tsum[j]-k)-1][a-1]%mod*w%mod);//=j+1
					add(g[j+1][k+t[j+1]-a],f[j][k]*C[i-(tsum[j]-k)-1][a]%mod*w%mod);//>j+1
				}
			}
			if(p[i]==1){
				for(int j=0;j<=n;j++) for(int k=tsum[j]-i+1;k<=tsum[j];k++) if(f[j][k]){
					add(g[j][k],f[j][k]%mod);//>j
					for(int a=0;a<=t[j+1];a++){
						ll w=C[t[j+1]][a]*jc[a]%mod;
						if(k+a) add(g[j+1][k+t[j+1]-a-1],f[j][k]*C[i-(tsum[j]-k)-1][a]%mod*k%mod*w%mod);//<=j
					}
				}
			}
			for(int j=0;j<=n;j++) for(int k=0;k<=n;k++){f[j][k]=g[j][k];g[j][k]=0;}
		}
		ll ans=0;
		for(int j=0;j<=n-m;j++) add(ans,f[j][0]*jc[n-tsum[j]]%mod);
		printf("%lld\n",ans);
	}
}
//bool f2;
int main(){
//	int _=clock();
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
//	read(T);
	while(T--) SOLVE::main();
//	cerr<<((&f2)-(&f1))/1024.0/1024.0<<endl;
//	cerr<<clock()-_<<endl;
	return 0;
}
