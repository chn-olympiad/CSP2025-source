#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
#define add(x,y) (x=((x+y>=mod)?(x+y-mod):(x+y)))
int const N=505,mod=998244353;
int n,m,c[N],p[N],f[20],g[20],fac[N],tot[N],C[N][N],ans;string s;
namespace SB1{
	int f[N],g[N];
	inline void work(){
		vector<int>V;
		rep(i,0,n-1) if (s[i]=='1') V.push_back(i+1);
		int sz=V.size(),ans=0;
		rep(S,0,0){
			int tt=0,la=0;
			memset(f,0,sizeof(f)),f[0]=1;
			rep(o,0,sz-1){
				int val=V[o]-tt-1;
				{
					memset(g,0,sizeof(g));
					//c[p[V[i]]]<=val
					rep(i,0,sz){
						if (!f[i]) continue;
						rep(p1,0,i) add(g[i-p1],1ll*f[i]*C[tot[val]-la][p1]%mod*fac[p1]%mod*C[i][p1]%mod);
					}
					memcpy(f,g,sizeof(f));
					rep(i,0,sz) if (f[i]){
						assert(tot[val]-(o-i)>=0);
						f[i]=1ll*f[i]*(tot[val]-(o-i))%mod;
					}
				}
				la=tot[val];
			}
			int res=0;
			rep(i,0,sz) add(res,1ll*f[i]*C[n-la][i]%mod*fac[i]%mod);
			add(ans,res);
		}
		int g=1;
		rep(i,1,n) if (s[i-1]=='0') ans=1ll*ans*g%mod,++g;
		cout<<(fac[n]+mod-ans)%mod<<'\n';
	}
}
namespace SB2{
	int f[N],g[N];
	inline void work(){
		vector<int>V;
		rep(i,0,n-1) if (s[i]=='1') V.push_back(i+1);
		int sz=V.size(),ans=0;
		{
			int tt=0,la=0;
			memset(f,0,sizeof(f)),f[0]=1;
			rep(o,0,sz-1){
				int val=V[o]-tt-1;
				{
					memset(g,0,sizeof(g));
					//c[p[V[i]]]>val
					rep(i,0,sz){
						if (!f[i]) continue;
						rep(p1,0,i) add(g[i-p1+1],1ll*f[i]*C[tot[val]-la][p1]%mod*fac[p1]%mod*C[i][p1]%mod);
					}
					memcpy(f,g,sizeof(f));
				}
				++tt,la=tot[val];
			}
			int res=0;
			rep(i,0,sz) add(res,1ll*f[i]*C[n-la][i]%mod*fac[i]%mod);
			add(ans,res);
		}
		int g=1;
		rep(i,1,n) if (s[i-1]=='0') ans=1ll*ans*g%mod,++g;
		cout<<ans<<'\n';
	}
}
inline void solve(){
	cin>>n>>m>>s;
	rep(i,1,n) cin>>c[i],++tot[c[i]];
	rep(i,1,n) tot[i]+=tot[i-1];
	if (m==1) return SB1::work();
	if (n==m) return SB2::work();
	vector<int>V;
	rep(i,0,n-1) if (s[i]=='1') V.push_back(i+1);
	int sz=V.size(),ans=0;
	rep(S,0,(1<<sz)-1){
		if (__builtin_popcount(S)<m) continue;
		int tt=0,la=0;
		memset(f,0,sizeof(f)),f[0]=1;
		rep(o,0,sz-1){
			int val=V[o]-tt-1;
			if (S>>o&1){
				memset(g,0,sizeof(g));
				//c[p[V[i]]]>val
				rep(i,0,sz){
					if (!f[i]) continue;
					rep(p1,0,i) add(g[i-p1+1],1ll*f[i]*C[tot[val]-la][p1]%mod*fac[p1]%mod*C[i][p1]%mod);
				}
				memcpy(f,g,sizeof(f));
			}else{
				memset(g,0,sizeof(g));
				//c[p[V[i]]]<=val
				rep(i,0,sz){
					if (!f[i]) continue;
					rep(p1,0,i) add(g[i-p1],1ll*f[i]*C[tot[val]-la][p1]%mod*fac[p1]%mod*C[i][p1]%mod);
				}
				memcpy(f,g,sizeof(f));
				rep(i,0,sz) if (f[i]){
					assert(tot[val]-(o-i)>=0);
					f[i]=1ll*f[i]*(tot[val]-(o-i))%mod;
				}
			}
			tt+=(S>>o&1),la=tot[val];
		}
		int res=0;
		rep(i,0,sz) add(res,1ll*f[i]*C[n-la][i]%mod*fac[i]%mod);
		add(ans,res);
	}
	int g=1;
	rep(i,1,n) if (s[i-1]=='0') ans=1ll*ans*g%mod,++g;
	cout<<ans<<'\n';
}
signed main(){
	freopen("employ4.in","r",stdin);
	// freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fac[0]=1;
	rep(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mod;
	rep(i,0,N-1){
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	int t=1;
	while (t--) solve();
	return 0;
}