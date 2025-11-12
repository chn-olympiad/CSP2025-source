#include<bits/stdc++.h>
using namespace std;
#define il inline
#define fi first
#define se second
#define mk make_pair
#define eb emplace_back
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define rep_(i,l,r) for(int i=(l); i>=(r); --i)
typedef long long lr;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T>il T Max(T x,T y) { return x>y? x:y; }
template<typename T>il T Min(T x,T y) { return x<y? x:y; }
constexpr int N=505,mod=998244353;
il void Reduce(int &_) { (_>=mod)&&(_-=mod); }
il int Poww(int x,int y)
{
	int mul=1; for( ; y; y>>=1,x=(ull)x*x%mod)
		if(y&1) mul=(ull)mul*x%mod; return mul;
}
int n,m,a[N],cnt[N],pre[N],fac[N],inv[N],c[N][N],f[N][N],g[N][N]; string s;
il void Solve()
{
	cin>>n>>m>>s,s=" "+s;
	rep(i,1,n)
		cin>>a[i],++cnt[a[i]];
	pre[0]=cnt[0];
	rep(i,1,n)
		pre[i]=pre[i-1]+cnt[i];
	fac[0]=1;
	rep(i,1,n)
		fac[i]=(ull)fac[i-1]*i%mod;
	inv[n]=Poww(fac[n],mod-2);
	rep_(i,n,1)
		inv[i-1]=(ull)inv[i]*i%mod;
	rep(i,0,n)
	{
		c[i][0]=1;
		rep(j,1,i)
			Reduce(c[i][j]=c[i-1][j]+c[i-1][j-1]);
	}
	f[0][0]=1;
	rep(i,0,n-1)
	{
		rep(j,0,n)
			rep(k,0,n)
			{
				if(!f[j][k]||pre[j]<i-k) continue;
				int res=pre[j]-(i-k);
				if(s[i+1]=='0')
				{
					rep(l,0,cnt[j+1])
					{
						if(k<l) break;
						int mul=(ull)f[j][k]*c[k][l]%mod*c[cnt[j+1]][l]%mod*fac[l]%mod,kk=k-l;
						if(res) g[j+1][kk]=(g[j+1][kk]+(ull)mul*res)%mod;
						if(l<cnt[j+1]) g[j+1][kk]=(g[j+1][kk]+(ull)mul*(cnt[j+1]-l))%mod;
						if(res<n-i) Reduce(g[j+1][kk+1]+=mul);
					}
					continue;
				}
				if(res<n-i) Reduce(g[j][k+1]+=f[j][k]);
				if(!res) continue;
				rep(l,0,cnt[j+1])
				{
					if(k<l) break;
					int mul=(ull)f[j][k]*c[k][l]%mod*c[cnt[j+1]][l]%mod*fac[l]%mod,kk=k-l;
					g[j+1][kk]=(g[j+1][kk]+(ull)mul*res)%mod;
				}
			}
		rep(j,0,n)
			rep(k,0,n)
				f[j][k]=g[j][k],g[j][k]=0;
	}
	int ans=0;
	rep(j,0,n)
		if(n-j>=m)
			rep(k,0,n)
				if(k==n-pre[j])
					ans=(ans+(ull)f[j][k]*fac[k])%mod;
	cout<<ans<<'\n';
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	while(T--)
		Solve();
	return 0;
}