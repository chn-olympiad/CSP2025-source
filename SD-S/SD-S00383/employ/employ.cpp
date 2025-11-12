#include<bits/stdc++.h>
#define eb emplace_back
#define SZ(s) ((int)s.size())
#define all(s) s.begin(),s.end()
#define gt getchar
#define pt putchar
typedef long long ll;
typedef double db;
const int N=505;
const int mod=998244353;
using namespace std;
template<class T,class I> inline bool chkmax(T &a,I b){return a<b?a=b,1:0;}
template<class T,class I> inline bool chkmin(T &a,I b){return a>b?a=b,1:0;}
inline bool __(char ch){return ch>=48&&ch<=57;}
template<class T> inline void read(T &x){
	x=0;char ch=gt();bool sgn=0;
	while(!__(ch)&&ch!=EOF) sgn|=(ch=='-'),ch=gt();
	while(__(ch)) x=(x<<1)+(x<<3)+(ch&15),ch=gt();
	if(sgn) x=-x;
}
template<class T,class ...I> inline void read(T &x,I &...x1){
	read(x);
	read(x1...);
}
int n,m,s[N],c[N],a[N],sum[N][2];
inline void add(int &a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}
namespace Sub1{
	int f[2][1<<18][20];
	inline bool in(int S,int i){return (S>>(i-1))&1;}
	#define popc(x) __builtin_popcount(x) 
	inline void solve(){
		f[0][0][0]=1; 
		for(int i=1;i<=n;++i){
			int p=i&1,q=p^1;
			for(int S=0;S<(1<<n);++S) for(int j=0;j<=i;++j) f[p][S][j]=0;
			for(int S=0;S<(1<<n);++S){
				if(popc(S)!=i) continue;
				for(int u=1;u<=n;++u){
					if(!in(S,u)) continue;
					int T=S^(1<<(u-1));
					for(int j=0;j<=i;++j){
						if(!f[q][T][j]) continue;
						if(s[i]&&j<c[u]) add(f[p][S][j],f[q][T][j]);
						else add(f[p][S][j+1],f[q][T][j]);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;++i) add(ans,f[n&1][(1<<n)-1][i]);
		printf("%d\n",ans);
	}
}
namespace Sub2{
	inline void solve(){
		for(int i=1;i<=n;++i) if(!s[i]||!c[i]) return printf("0\n"),void();
		int ans=1;
		for(int i=1;i<=n;++i) ans=1ll*ans*i%mod;
		printf("%d\n",ans); 
	}
}
namespace Sub3{
	inline bool check(){
		for(int i=1;i<=n;++i) if(!s[i]) return 0;
		return 1;
	}
	int f[N][N][N],cnt[N],sum[N],binom[N][N],fac[N];
	inline void solve(){
		for(int i=1;i<=n;++i) cnt[a[i]]++;
		sum[0]=cnt[0],fac[0]=1;
		for(int i=1;i<=n;++i) sum[i]=sum[i-1]+cnt[i],fac[i]=1ll*fac[i-1]*i%mod;
		binom[0][0]=1;
		for(int i=1;i<=n;++i){
			binom[i][0]=1;
			for(int j=1;j<=i;++j) binom[i][j]=(binom[i-1][j]+binom[i-1][j-1])%mod;
		}
		f[0][0][n-cnt[0]]=1;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n;++j){
				for(int k=0;k<=n;++k){
					if(!f[i-1][j][k]) continue;
					if(k) add(f[i][j][k-1],f[i-1][j][k]);
					if(sum[j]>=j){
						for(int p=0;p<=min(k,cnt[j]);++p){
							add(f[i][j+1][k-p],1ll*f[i-1][j][k]*(sum[j]-j+1)%mod*binom[k][p]%mod*fac[p]%mod);
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;++i) for(int j=0;j<=n;++j) add(ans,1ll*f[n][i][j]*fac[j]%mod);
		printf("%d\n",ans);
	}
}
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	file("employ");
	read(n,m);
	for(int i=1;i<=n;++i){
		scanf("%1d",&s[i]);
		for(int j=0;j<2;++j) sum[i][j]=sum[i-1][j];
		sum[i][s[i]]++;
	}
	for(int i=1;i<=n;++i){
		read(c[i]);
		int sum=0;
		for(int j=1;j<=n;++j){
			if(sum<c[i]) a[i]=j,sum+=s[j];
			else break;
		}
	}
	if(n<=18) Sub1::solve();
	else if(m==n) Sub2::solve();
	else if(Sub3::check()) Sub3::solve();
	return 0;
}
