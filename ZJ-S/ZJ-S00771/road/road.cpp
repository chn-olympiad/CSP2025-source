#include<bits/stdc++.h>
using namespace std;
#define int long long 
int const N=1000001;
int n,m,k;
struct edge{
	int u,v,w;
}e[N],e1[N];
int c[11][1001];
int d[1001][1001],vis[1001][1001];
int d1[1001][1001],vis1[1001][1001];
int f[1001];
int xz[11];
int flag=0;
int find(int x)
{
	if(x==f[x])
		return x;
	return f[x]=find(f[x]);
}	
bool cmp(edge t1,edge t2)
{
	return t1.w<t2.w;
}	
int ans;
int ans1=LLONG_MAX;
void cl()
{
	for(int i=1;i<=n;i++)	
		for(int j=i+1;j<=n;j++)
			vis[i][j]=vis1[i][j],d[i][j]=d1[i][j];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			{
				for(int h=1;h<=k;h++)
				{
					if(xz[h]==1)
					{
						int dis=c[h][i]+c[h][j]+c[h][0];
						if(vis[i][j]==0)
						{
							d[i][j]=dis;
							vis[i][j]=1;
						}
						else if(d[i][j]>dis)
							d[i][j]=dis;
					}
				}	
			}	
		int js=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(vis[i][j]==1)
				{
					e[++js]={i,j,d[i][j]};
				}	
			}
		for(int i=1;i<=n;i++)
			f[i]=i;
		sort(e+1,e+js+1,cmp);
		int sum=0;
		ans=0;
		for(int i=1;i<=js;i++)
		{
			int u=e[i].u,v=e[i].v,w=e[i].w;
			int fx=find(u),fy=find(v);
			if(fx!=fy)
			{
				f[fy]=fx;
				sum++;
				ans+=w;
			}	
			if(sum==n-1)	
				break;
		}	
}
void pts_1()
{
	for(int i=1;i<=k;i++)	
		xz[i]=1;
	//cout<<"*"<<'\n';
	cl();
	cout<<ans<<'\n';
	return ;
}
void dfs(int x)
{
	if(x==k+1)
	{
		cl();
		if(ans<ans1)
			ans1=ans;
		return ;
	}	
	xz[x]=1;
	dfs(x+1);
	xz[x]=0;
	dfs(x+1);
}	
void pts_2()
{
	//cout<<"*"<<'\n';
	dfs(1);
	cout<<ans1<<'\n';
	return ;
}	
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)	
	{
		int u,v,w;
		cin>>u>>v>>w;
		e1[i].u=u,e1[i].v=v,e1[i].w=w;
		if(vis1[u][v]==0)
		{
			d1[u][v]=w;
			vis1[u][v]=1;
			d1[v][u]=w;
			vis1[v][u]=1;
		}
		else if(d1[u][v]>w)
		{
			d1[u][v]=w;
			d1[v][u]=w;
		}
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
		{
			cin>>c[i][j];
			if(c[i][0]!=0)
			{
				flag=1;
			}
		}
	//cout<<flag<<'\n';
	if(flag==0)
		pts_1();
	else 
		pts_2();
	return 0;
}
