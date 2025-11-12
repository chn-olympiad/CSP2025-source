#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int x,y;
	long long z;
	bool operator < (const node&W)const
	{
		return z<W.z;
	}
}e[1000010];
int c[100010];
int a[20][100010];
int fa[100010];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
long long g[1010][1010];
long long g1[1010][1010];
int main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		g[max(x,y)][min(x,y)]=min(g[max(x,y)][min(x,y)],1ll*z);
		e[i]={x,y,z};
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	if(k<=0)
	{
		sort(e+1,e+1+m);
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			if(find(e[i].x)!=find(e[i].y))
			{
				fa[find(e[i].x)]=find(e[i].y);
				ans+=e[i].z;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=1000&&k<=5)
	{
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		}
		long long answer=LLONG_MAX;
		for(int s=0;s<(1<<k);s++)
		{
			memcpy(g1,g,sizeof(g1));
			long long ans=0;
			for(int j=1;j<=k;j++)
			{
				if((s>>(j-1))&1)
				{
					ans+=c[j];
					for(int i=1;i<=n;i++)
					{
						for(int z=1;z<i;z++)
						{
							g1[i][z]=min(g1[i][z],1ll*(1ll*a[j][i]+1ll*a[j][z]));
						}
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				fa[i]=i;
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<i;j++)
				{
					e[++cnt]={i,j,g1[i][j]};
				}
			}
			sort(e+1,e+1+cnt);
			for(int i=1;i<=cnt;i++)
			{
				if(find(e[i].x)!=find(e[i].y))
				{
					fa[find(e[i].x)]=find(e[i].y);
					ans+=e[i].z;
					if(ans>answer)
					{
						break;
					}
				}
			}
			answer=min(answer,ans);
		}
		cout<<answer<<'\n';
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<j;k++)
				{
					g[j][k]=min(g[j][k],1ll*(1ll*a[i][j]+1ll*a[i][k]+1ll*c[i]));
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				e[++cnt]={i,j,g[i][j]};
			}
		}
		sort(e+1,e+1+cnt);
		long long ans=0;
		for(int i=1;i<=cnt;i++)
		{
			if(find(e[i].x)!=find(e[i].y))
			{
				fa[find(e[i].x)]=find(e[i].y);
				ans+=e[i].z;
			}
		}
		cout<<ans;
	}
	
	return 0;
}