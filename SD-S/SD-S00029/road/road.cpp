#include <bits/stdc++.h>
using namespace std;
#define int long long int
struct node
{
	int to;
	int val;
};
const int maxn=1e4+4;
const int BIG=1e12;
vector<node> g[maxn];
bool vis[maxn];
int dis[maxn];
int n,m,k;
int ans=0;
int a[11][maxn];
int d[11];
int c[maxn];
int tot=0;
struct edge
{
	int point;
	int dis;
	
	bool operator < (const edge &a) const
	{
		return a.dis<dis;
	}
};
priority_queue<edge> q;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
//200pts
int quick_pow(int rp1,int rp2)
{
	if(!rp2)
	{
		return 0;
	}
	int res=1;
	int base=rp1;
	while(rp2>0)
	{
		if(rp2&1)
		{
			res*=base;
		}
		base*=base;
		rp2>>=1;
	}
	return res;
}
void prim()
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=BIG;
	}
	dis[1]=0;
	q.push((edge){1,0});
	while(!q.empty())
	{
		int u=q.top().point;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		ans+=dis[u];
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].to;
			int w=g[u][i].val;
			if(dis[v]>w)
			{
				dis[v]=w;
				q.push((edge){v,w});
			}
		}
	}
}
void prim1()
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=BIG;
	}
	dis[1]=0;
	q.push((edge){1,0});
	while(!q.empty())
	{
		int u=q.top().point;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		tot+=dis[u];
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].to;
			int w=g[u][i].val;
			if(dis[v]>w)
			{
				dis[v]=w;
				q.push((edge){v,w});
			}
		}
	}
}
void begin()
{
	while(!q.empty())
	{
		q.pop();
	}
}
signed main ()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		u=read();
		v=read();
		w=read();
		g[u].push_back((node){v,w});
		g[v].push_back((node){u,w});
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	prim();
	for(int i=1;i<=quick_pow(2,k);i++)
	{
		begin();
		for(int j=1;j<=k;j++)
		{
			if(d[j])
			{
				if(c[j]>ans)
				{
					continue;
				}
				tot=1e12;
				tot+=c[j];
				for(int k=0;k<g[j].size();k++)
				{
					if(g[j][k].val>a[j][g[j][k].to])
					{
						g[j][k].val=a[j][g[j][k].to];
					}
					else if(!g[j][k].val)
					{
						g[j].push_back((node){k,a[j][g[j][k].to]});
						g[k].push_back((node){j,a[j][g[j][k].to]});
					}
				}
				
			}
			
		}
		prim1();
				ans=min(ans,tot);
		d[1]++;
		int cnt=1;
		while(d[cnt]==2)
		{
			d[++cnt]++;
			d[cnt-1]=0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
