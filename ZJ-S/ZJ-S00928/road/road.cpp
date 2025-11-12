#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	int x,y,w;
};
const int N=1e3+5,M=1e8+5;
ll n,m,k,lst,sum;
edge e[M];
ll c[15][N],_c[15];
ll a[N][N],b[N][N],top[N];
void init()
{
	for(int i=1;i<=n;i++)
		top[i]=i;
}
int find(int x)
{
	if(x==top[x])	return x;
	return top[x]=find(top[x]);
}
bool cmp(edge e1,edge e2)
{
	return e1.w<e2.w;
}
void kruskal()
{
	sum=0;
	sort(e+1,e+lst+1,cmp);
	init();
	for(int i=1;i<=lst;i++)
	{
		int x=e[i].x,y=e[i].y,w=e[i].w;
		int tx=find(x),ty=find(y);
		if(tx==ty)	continue;
		top[tx]=ty;
		sum+=w;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>_c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}	
	}
	ll mn=1000000000000;
	for(int tp=0;tp<(1<<k);tp++)
	{
		ll ans=0,num=tp;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				b[i][j]=a[i][j];
			}
		}
		for(int i=1;i<=10;i++)
		{
			if(num&1)
			{
				ans+=_c[i];
				for(int x=1;x<=n;x++)
				{
					for(int y=x+1;y<=n;y++)
					{
						if(b[x][y]!=-1)	b[x][y]=b[y][x]=min(b[x][y],c[i][x]+c[i][y]);
						else	b[x][y]=b[y][x]=c[i][x]+c[i][y];
					}
				}
			}
			num/=2;
		}
		lst=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(b[i][j]!=-1)
				{
					e[++lst]=(edge){i,j,b[i][j]};
				}
			}
		}
		kruskal();
		ans+=sum;
		mn=min(mn,ans);
	}
	cout<<mn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
