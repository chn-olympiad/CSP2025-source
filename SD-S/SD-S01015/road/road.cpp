// 华风夏韵，洛水天依！
// 天依宝宝可爱！> <

#include<bits/stdc++.h>

#define int long long
#define ll long long
#define il inline
#define i128 __int128
#define double long double
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rpe(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb emplace_back

using namespace std;
bool memory_begin;

const int N=1e4+712,M=1e6+5,V=6e5+5,mod=998244353;
const double eps=1e-9;

il void read(   signed& x){char c;while((c=getchar())<'0'||c>'9');x=c^48;while((c=getchar())>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48);}
il void read(long long& x){char c;while((c=getchar())<'0'||c>'9');x=c^48;while((c=getchar())>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48);}

template <typename T> il T& add(T& a,T b){return (a+=b)>=mod&&(a-=mod),a;}
template <typename T> il T& chmax(T& a,T b){return b>a&&(a=b),a;}
template <typename T> il T& chmin(T& a,T b){return a>b&&(a=b),a;}

#define multiple_test 0
int __T=1,test_id;

int n,m,k;
ll ans=0,c[712];
struct edge{int u,v; ll w;} e[M],a[11][N],f[11][N<<1],t[11][N<<1];

il bool edge_cmp(const edge& a,const edge& b){return a.w<b.w;}

struct __dsu
{
	int fa[N<<1],rk[N<<1],n;
	il void init(int _n){n=_n; rep(i,1,n) fa[i]=i,rk[i]=0;}
	il int find(int x){return x^fa[x]?fa[x]=find(fa[x]):fa[x];}
	il bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return 0;
		rk[x]^rk[y]?(rk[x]>rk[y]?(fa[y]=x):(fa[x]=y)):(fa[y]=x,++rk[x]);
		return 1;
	}
} dsu;

namespace krus1
{
	il ll work()
	{
		dsu.init(n);
		sort(e+1,e+m+1,edge_cmp);
		int u,v,w,tot=0; ll ans=0;
		rep(i,1,m)
		{
			u=e[i].u,v=e[i].v,w=e[i].w;
			if(!(dsu.merge(u,v))) continue;
			a[k][++tot]=(edge){u,v,w},ans+=w;
			if(tot==n-1) break;
		}
		return ans;
	}
}

namespace krus2
{
	il ll work(int n,int m,edge *e,int dep)
	{
		dsu.init(n+20);
		int u,v,w,tot=0; ll ans=0;
//		sort(e+1,e+m+1,edge_cmp);
		rep(i,1,m)
		{
			u=e[i].u,v=e[i].v,w=e[i].w;
			if(!(dsu.merge(u,v))) continue;
			t[dep][++tot]=(edge){u,v,w},ans+=w;
			if(tot==n-1) break;
		}
		return ans;
	}
}

il void dfs(int dep,int pos,int _n,int _m,ll now)
{
	if(now>=ans) return;
	if(pos) chmin(ans,now+krus2::work(_n,_m,f[dep],dep));
	if(pos==k) return;
	
	int tot,i,j;
	rep(p,pos,k-1)
	{
		tot=0;
		for(i=1,j=1;i<=_n-1&&j<=n;) t[dep][i].w<a[p][j].w ? (f[dep+1][++tot]=t[dep][i],++i) : (f[dep+1][++tot]=a[p][j],++j);
		for(;i<=_n-1;++i) f[dep+1][++tot]=t[dep][i];
		for(;j<=n;++j) f[dep+1][++tot]=a[p][j];
		
//		if(tot^_m+n) cerr<<"[ERROR!!!] "<<tot<<' '<<_m<<' '<<n<<'\n',exit(0);
		dfs(dep+1,p+1,_n+1,tot,now+c[p]);
	}
}

il void solve()
{
	read(n),read(m),read(k); rep(i,1,m) read(e[i].u),read(e[i].v),read(e[i].w);
	rep(i,0,k-1)
	{
		read(c[i]);
		rep(j,1,n) read(a[i][j].w),a[i][j].u=n+i+1,a[i][j].v=j;
		sort(a[i]+1,a[i]+n+1,edge_cmp);
	}
	
	ans=krus1::work();
	rep(i,1,n-1) f[0][i]=a[k][i],t[0][i]=a[k][i];
	dfs(0,0,n,n-1,0);
	
	printf("%lld",ans);
}

il void init()
{

}

bool memory_end;
signed main()
{
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0);
//	fprintf(stderr,"memory = %.3f MB\n\n",abs(&memory_begin-&memory_end)/1024./1024.);
	init(); multiple_test&&(scanf("%lld",&__T),1);
	rep(__Ti,1,__T) solve();
//	fprintf(stderr,"\ntime = %.3f ms\n",clock()*1e3/CLOCKS_PER_SEC);
	return 0;
}

