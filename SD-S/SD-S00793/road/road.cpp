#include<bits/stdc++.h>
using namespace std;
int a[15],vis[15],g[10005],cnt;
int q[15][10005],b[10005][10005];
long long ans;
struct abc
{
	int u,v,w; 
}s[2000005];
bool cmp(abc e,abc f)
{
	return e.w<f.w;
}
int find(int x)
{
	if (g[x]!=x)
	{
		g[x]=find(g[x]);
	}
	return g[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		g[i]=i;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>a[i];
		for (int j=1;j<=n;j++)
		{
			cin>>q[i][j];
		}
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int p=j+1;p<=n;p++)
			{
				if (i==1)
				{
					b[j][p]=q[i][j]+q[i][p]+a[i];
				}
				else
				{
					b[j][p]=min(q[i][j]+q[i][p]+a[i],b[j][p]);
				}
			}
		}
	}
	cnt=m;
	for (int j=1;j<=n;j++)
	{
		for (int p=j+1;p<=n;p++)
		{
			cnt++;
			s[cnt].u=j;
			s[cnt].v=p;
			s[cnt].w=b[j][p];
		}
	}
	sort(s+1,s+cnt+1,cmp);
	int x,y,z,gx,gy;
	for (int i=1;i<=cnt;i++)
	{
		x=s[i].u,y=s[i].v,z=s[i].w;
		gx=find(x),gy=find(y);
		if (gx!=gy)
		{
			g[gy]=gx;
			ans+=s[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
