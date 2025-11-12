#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
const int N=2e5+5,M=2e6+5;
const ll inf=1e18;
struct dsu
{
	int fa[N];
	inline void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	inline int f(int x){return fa[x]==x?x:fa[x]=f(fa[x]);}
	inline void m(int x,int y){fa[f(x)]=f(y);}
	inline bool s(int x,int y){return f(x)==f(y);}
}s;
struct __edge
{
	int u,v,w;
	bool operator<(const __edge y) const
	{
		return w<y.w;
	}
	bool operator>(const __edge y) const
	{
		return w>y.w;
	}
}e[M],g[20][N];
int c[20],fr[20];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,e[i]={u,v,w};
	sort(e+1,e+m+1);
	s.init(n);
	for(int i=1,cnt=0;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(s.s(u,v)) continue;
		ans+=w,s.m(u,v),g[0][++cnt]={u,v,w};
	}
	g[0][n]={0,0,inf};
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1,v;j<=n;j++) cin>>v,g[i][j]={n+i,j,v};
		sort(g[i]+1,g[i]+n+1);
		g[i][n+1]={0,0,inf};
	}
//	cerr<<ans<<"\n";
	for(int st=1;st<(1<<k);st++)
	{
		using node=pair<__edge,int>;
		priority_queue<node,vector<node>,greater<node>> pq;
		int sum=0,cnt=n,cc=1;
		pq.push({g[0][1],0});
		for(int j=1;j<=k;j++) if(st&(1<<(j-1))) pq.push({g[j][1],j}),sum+=c[j],cnt++,cc++;
		for(int j=0;j<=k;j++) fr[j]=1;
		s.init(n+k);
		for(int i=1;cnt>1&&i<=cc*n;i++)
		{
			auto ee=pq.top().first;int id=pq.top().second;pq.pop();
			int u=ee.u,v=ee.v,w=ee.w;
			if(w==inf) continue;
			if(!s.s(u,v)) sum+=w,s.m(u,v),cnt--;
			if(fr[id]<n) pq.push({g[id][++fr[id]],id});
		}
		ans=min(ans,sum);
//		cerr<<st<<":"<<sum<<"\n";
	}
	cout<<ans<<"\n";
//	cerr<<clock()<<"\n";
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

// AVENGER_M & sanyueyetu
// zhu wo bu yao gua fen

// I MISS HER
