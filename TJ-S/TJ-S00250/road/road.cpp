#include<bits/stdc++.h> 
using namespace std;
#define int long long

struct node
{
	int u,v,w;
}e[2100008];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int n,m,k,c[15],a[15][1000006],cnt,fa[10004],ans;
int find (int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	else
	{
		return fa[x]=find(fa[x]);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cnt++;
		cin>>e[i].u>>e[i].v>>e[i].w;
	}

	for(int i=1;i<=k;i++)
	{
		cin>>c[i];		
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}			
		if(c[i]==0)
		{
			for(int j=1;j<=n;j++)
			{
				for(int t=j+1;t<=n;t++)
				{
					if(j==t)
					{
						continue;
					}
					cnt++;
					e[cnt].u=j;
					e[cnt].v=t;
					e[cnt].w=a[i][j]+a[i][t];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(e+1,e+cnt+1,cmp);
	int num=0;
	for(int i=1;i<=cnt&&num<=n;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			fa[find(e[i].u)]=find(e[i].v);
			ans+=e[i].w;
			num++;
		}
	}
	cout<<ans;
}
