#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rg register
#define INT_MAX 0x7fffffff
#define LL_INT_MAX 0x7fffffffffffffffll
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
namespace io
{
	template<typename T> inline void iread(T &x)
	{
		x=0; char c=' '; int w=1;
		while(!isdigit(c)&&c!='-') c=getchar();
		if(c=='-'){w=-1; c=getchar();}
		while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	}
}
using io::iread;
const int N=1e4+30,M=1e6+1e5+10;
int n,m,k,cnt;
ll ans=LL_INT_MAX;
struct edge
{
	int u,v;
	ll w;
	bool operator <(edge a)
	{
		if(w==a.w) return u<a.u;
		return w<a.w;
	}
}e[M];
int fa[N];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void bin_set_init()
{
	for(int i=1;i<=n+k;++i)
		fa[i]=i;
}
ll c[15];
bool use[15];
inline ll kru(ll pre)
{
	ll sum=0;
	bin_set_init();
	for(int i=1;i<=cnt&&ans>sum+pre;++i)
	{
		if(e[i].u>n&&!use[e[i].u-n]) continue;
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		fa[fu]=fv; sum+=e[i].w;
	}
	return sum;
}
void dfs(int s,ll sum)
{
	if(s==k+1)
	{
		ll ans1=sum+kru(sum);
		ans=min(ans,ans1);
		return ;
	}
	use[s]=0;
	dfs(s+1,sum);
	use[s]=1;
	dfs(s+1,sum+c[s]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v; ll w;
	for(int i=1;i<=m;++i)
	{
		iread(u);
		iread(v);
		iread(w);
		e[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;++i)
	{
		iread(c[i]);
		for(int j=1;j<=n;++j)
		{
			iread(w);
			e[++cnt]={n+i,j,w};
		}
	}
	sort(e+1,e+cnt+1);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
