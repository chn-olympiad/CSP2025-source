#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Edge
{
	int u,v,w;
}e[1000001];
int h[10001],idx,c[11][10001],k,n;
bool vi[10001],vis[11];
int add(int u,int v,int w)
{
	e[idx].u=h[u];
	e[idx].v=v;
	e[idx].w=w;
	h[u]=idx++;
}
long long prim(int s)
{
	memset(vis,0,sizeof(vis));
	memset(vi,0,sizeof(vi));
	queue <int> q;
	q.push(s);
	vi[s]=1;
	long long ans=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		int miv=-1,minnw=0x3f3f3f3f,t=0;
		for(int i=h[u];~i;i=e[i].u)
		{
			int v=e[i].v;
			if(vi[v]==1)
			{
				continue;
			}
			if(minnw>e[i].w)
			{
				minnw=e[i].w;
				miv=v;
				t=0;
			}
		}
		for(int v=1;v<=n;v++)
		{
			if(vi[v])
			{
				continue;
			}
			if(v==u)
			{
				continue;
			}
			for(int j=1;j<=k;j++)
			{
				if(!vis[j])
				{
					if(minnw>=c[j][u]+c[j][v]+c[j][0])
					{
						t=j;
						minnw=c[j][u]+c[j][v]+c[j][0];
						miv=v;
					}
				}
				else
				{
					if(minnw>=c[j][u]+c[j][v])
					{
						t=j;
						minnw=c[j][u]+c[j][v];
						miv=v;
					}
				}
			}	
		}
		if(miv==-1)
		{
			continue;
		}
		if(t)
		{
			vis[t]=1;
		}
		ans+=minnw;
		vi[miv]=1;
		q.push(miv);
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin>>n>>m>>k;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	long long minn=2e9;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,prim(i));
	}
	cout<<minn;
	return 0;
} 
