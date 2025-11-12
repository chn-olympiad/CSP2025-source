#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5; 
int n,m,k,fa[N],ans,c[20],a[N][N],b[20][N],size[N];
bool flag1=1;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
void ff(int x,int y)
{
	if(size[x]<=size[y])
	{
		fa[x]=fa[y];
	}
	else
	{
		fa[y]=fa[x];
	}
	size[x]+=size[y];
	size[y]+=size[x];
	return; 
}
int find(int x)
{
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
void f()
{
	while(!pq.empty())
	{
		int u=pq.top().second.first,v=pq.top().second.second,w=pq.top().first;
		if(find(u)!=find(v))
		{
			ff(u,v);
			ans+=w;
		}
		pq.pop();
	}
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
		if(c[i]!=0)	flag1=0;
	}
	if(flag1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int l=1;l<=k;l++)
				{
					if(a[i][j]>b[l][i]+b[l][j])
					{
						a[i][j]=b[l][i]+b[l][j];
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i][j]!=-1)
			{
				int u=i,v=j,w=a[i][j];
				pq.push(make_pair(w,make_pair(u,v)));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		size[i]=1;
	}
	f();
	cout<<ans;
	return 0;
}
