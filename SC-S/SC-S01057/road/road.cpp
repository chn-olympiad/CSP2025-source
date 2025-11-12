#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef long long ll;
const int N=10050,K=50,INF=0x3f3f3f3f;

int n,m,k;
int g[N][N];
int c[K],nw[K][N];
int dist[N];
bool st[N];

ll solve(int newn)
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	memset(st,0,sizeof st);
	
	ll res=0;
	for(int i=1;i<=newn;i++)
	{
		int t=-1;
		for(int j=1;j<=newn;j++)
			if(!st[j]&&(t==-1||dist[t]>dist[j]))
				t=j;
		
		res+=dist[t];
		st[t]=true;
		for(int j=1;j<=newn;j++)
			dist[j]=min(dist[j],g[t][j]);
	}
	
	return res;
} 

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=n+20;i++)
		for(int j=1;j<=n+20;j++)
			g[i][j]=g[j][i]=INF;
	
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		g[a][b]=g[b][a]=min(g[a][b],w);
	}
	
	for(int i=0;i<k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&nw[i][j]);
	}
	
	ll ans=1e18,res=0;
	int newnode=n;
	for(int i=0;i<(1<<k);i++)
	{
		res=0,newnode=n;
		
		for(int j=0;j<k;j++)
			if(i>>j&1)
			{
				res+=c[j];
				newnode++;
				for(int t=1;t<=n;t++)
					g[newnode][t]=g[t][newnode]=min(g[t][newnode],nw[j][t]);
			}
		
		res+=solve(newnode);
		ans=min(ans,res);
		
		for(int j=n+1;j<=newnode;j++)
			for(int t=1;t<=n;t++)
				g[j][t]=g[t][j]=INF;
	}
	
	printf("%lld\n",ans);
	return 0;
} 