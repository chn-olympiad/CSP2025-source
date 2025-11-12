//48pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+105;
const int maxm=2e6+5;
const int maxk=15;
int n,m,k;
struct edge{
	int u,v,w;
	bool operator<(const edge &b)const
	{
		return this->w<b.w;
	}
}side[maxm];
struct node{
	int v,w;
};
int ans;
vector<node> e[maxn];
int c[maxk];
int dis[maxk][maxn];
int read()
{
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
int dad[maxn];
int _find(int x)
{
	return x==dad[x]?x:dad[x]=_find(dad[x]);
}
void _merge(int x,int y)
{
	dad[_find(x)]=_find(y);
}
struct point{
	int v,w;
	bool operator<(const point &b)const
	{
		return this->w>b.w;
	}
};
int vis[maxn];
int prim(int s)
{
	memset(vis,0,sizeof vis);
	int ans=0;
	priority_queue<point> q;
	q.push({s,0});
	while(!q.empty())
	{
		point t=q.top();
		q.pop();
		if(vis[t.v])continue;
		ans+=t.w;
		vis[t.v]=1;
		for(auto i:e[t.v])
		{
			if(!vis[i.v])q.push({i.v,i.w});
		}
	}
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	if(m<=1e5)
	{
		for(int i=1;i<=m;++i)
		{
			int u=read(),v=read(),w=read();
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		
		for(int i=1;i<=k;++i)
		{
			c[i]=read();
			for(int j=1;j<=n;++j)
			{
				dis[i][j]=read();
			}
		}
		ans=prim(1);
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=n;++j)
			{
				e[j].push_back({i+n,dis[i][j]});
				e[i+n].push_back({j,dis[i][j]});
			}
			int res=prim(1)+c[i];
			if(res<=ans)
			{
				ans=res;
			}
			else
			{
				e[i+k].clear();
				for(int j=1;j<=n;++j)e[j].pop_back();
			}
		}
		printf("%lld",ans);
	}
	else
	{
		for(int i=1;i<=n+k;++i)dad[i]=i;
		for(int i=1;i<=m;++i)
		{
			side[i].u=read();
			side[i].v=read();
			side[i].w=read();
		}
		int cnt=m;
		for(int i=1;i<=k;++i)
		{
			c[i]=read();
			for(int j=1;j<=n;++j)
			{
				++cnt;
				side[cnt].w=read();
				side[cnt].u=i+n;
				side[cnt].v=j;
			}
		}
		
		sort(side+1,side+cnt+1);
		int area=n+k;
		for(int i=1;i<=cnt;++i)
		{
			if(_find(side[i].u)!=_find(side[i].v))
			{
				_merge(side[i].u,side[i].v);
				--area;
				ans+=side[i].w;
				if(area==1)break;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
