#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10,INF=0X3f3f3f;
int g[N+10][N+10];
int n,m,k;
int a[N+10];
int d[N+10];
bool hsh[N+10];

void dijkstra(int qd)
{
	memset(d,0x3f,sizeof(d));
	memset(hsh,0,sizeof(hsh));
	d[qd]=0;
	
	for(int i=1;i<=n-1;i++)
	{
		int x=-1;
		for(int j=1;j<=n;j++)
			if(hsh[j]==0 && (x==-1||d[j]<d[x])) x=j;
		
		for(int y=1;y<=n;y++)
		{
			if(g[x][y]<INF)
			{
				d[y]=min(d[y],g[x][y]+d[x]);
			}
		}
		hsh[x]=1;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	memset(g,0x3f,sizeof(g));
	
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
	}
	
	for(int i=1;i<=k;i++)
	{
		int c; cin>>c;
		for(int j=1;j<=n;j++) cin>>a[j];
	}
	
	dijkstra(1);
	
	cout<<d[];

	return 0;
}
