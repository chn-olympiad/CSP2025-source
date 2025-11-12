#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int M=10010;
const int N=1000010;
int n,m,k,ans=0;
int g[M][M];

int dist[N],pre[N];
bool v[N];
void prime()
{
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	int t=-1;
	for(int i=1;i<=n;i++)
	{
		t=-1;
		for(int j=1;j<=n;j++)
		{
			if((t==-1||dist[t]>dist[j])&&!v[j])
			{
				t=j;
			}
		}
		v[t]=1;
		ans+=dist[t];
		for(int j=1;j<=n;j++)
		{
			if(dist[j]>=g[t][j])
			{
				dist[j]=g[t][j];
			}
		}

	}
}

int dist2[M];
bool v2[M];

int dij(int a,int b)
{
	memset(dist2,0x3f,sizeof(dist2));
	dist2[a]=0;
	for(int i=1;i<=n;i++)
	{
		int t=-1;
		for(int j=1;j<=n;j++)
		{
			if((t==-1||dist2[t]>dist2[j])&&!v2[j])
			{
				t=j;
			}
		}
		v2[t]=1;
		for(int j=1;j<=n;j++)
		{
			if(!v2[j]&&dist2[j]>dist2[t]+g[t][j])
			{
				dist2[j]=dist2[t]+g[t][j];
			}
		}
	}
	return dist2[b];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(g,0x3f-2,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=g[b][a]=min(g[a][b],c);

	}
	int x[M];
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
//		for(int j=1;j<=n;j++)
//		{
//			for(int k=1;k<=n;k++)
//			{
//				
//				if(x[j]+x[k]+c<dij(j,k))
//				{
//					ans=ans-dij(j,k)+(x[j]+x[k]+c);
//				}
//			}
//		}
		
	}
	prime();
	//cout<<dij(1,4)<<endl;
	cout<<ans<<endl;
	return 0;
	/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
 } 
