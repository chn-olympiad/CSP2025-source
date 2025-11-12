#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

#define int long long

#define INF 114514191981010086

using namespace std;

const int MAXN = 1e4+15;
const int MAXM = 1e6+5;

struct Edge
{
	int u,v,w;
	
	bool operator < (const Edge &e) const
	{
		return w < e.w;
	}
};

int read();
int findn(int x);
int Kruskal();

void unionn(int x, int y);
void clr();
int isrt(int x);

int n,m,k,ans=INF,rp;

int c[15],fa[MAXN];

Edge g[MAXM],tmpg[MAXM+12*MAXN];
Edge eg[15][MAXN];

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1; i<=m; i++)
	{
		g[i].u=read();
		g[i].v=read();
		g[i].w=read();
	}
	for(int i=1; i<=k; i++)
	{
		c[i]=read();
		for(int j=1; j<=n; j++)
		{
			int w=read();
			eg[i][j].w=w;
			eg[i][j].u=i;
			eg[i][j].v=j;
		}
	}
	sort(g+1,g+m+1);
	if(k == 0)
	{
		for(int i=1; i<=n; i++)
		{
			fa[i]=i;
		}
		ans=0;
		for(int i=1; i<=m; i++)
		{
			if(findn(g[i].u) == findn(g[i].v))
			{
				continue;
			}
			unionn(g[i].u,g[i].v);
			ans+=g[i].w;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=0; i<=(1<<k)-1; i++)
		{
			clr();
			int tmp=isrt(i);
			ans=min(ans,Kruskal()+tmp);
		}
		cout<<ans;
	}
	return 0;
}

int read()
{	
	int d=0,f=1;
	char c=getchar();
	while(c > '9' || c < '0')
	{
		if(c == '-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c >= '0' && c <= '9')
	{
		d=(d<<3)+(d<<1)+c-'0';
		c=getchar();
	}
	return d*f;
}

int findn(int x)
{
	return x == fa[x] ? x : fa[x]=findn(fa[x]);
}

void unionn(int x, int y)
{
	fa[findn(x)]=findn(y);
	return;
}

void clr()
{
	memset(tmpg,0,sizeof(tmpg));
	rp=0;
	for(int i=1; i<=n+k; i++)
	{
		fa[i]=i;
	}
	return;
}

int isrt(int x)
{
	int res=0;
	bool vis[15]={};
	for(int i=1; i<=k; i++)
	{
		if(x & 1)
		{
			vis[i]=true;
			res+=c[i];
			rp++;
		}
		x>>=1;
		if(!x)
		{
			break;
		}
	}
	int id=0;
	int pos[15]={};
	for(int i=1; i<=k; i++)
	{
		if(vis[i])
		{
			pos[i]=1;
		}
	}
	int c=0;
	for(int i=1; i<=m+rp*n; i++)
	{
		int minp=0,minx=g[pos[0]].w;
		for(int j=1; j<=k; j++)
		{
			if(eg[j][pos[j]].w < minx && vis[j])
			{
				minp=j;
				minx=eg[j][pos[j]].w;
			}
		}

		if(minp == 0)
		{
			tmpg[++c]=g[pos[0]];
		}
		else
		{
			tmpg[++c]=eg[minp][pos[minp]];
		}
		pos[minp]++;
	}
	return res;
}

int Kruskal()
{
	int res=0;
	sort(tmpg,tmpg+m+n*rp+1);
	for(int i=1; i<=m+n*rp; i++)
	{
		if(findn(tmpg[i].u) == findn(tmpg[i].v))
		{
			continue;
		}
		unionn(tmpg[i].u,tmpg[i].v);
		res+=tmpg[i].w;
	}
	return res;
}
