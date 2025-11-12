#include<bits/stdc++.h>
using namespace std;
long long minn=9223372036854775804;
long long n,m,k,a[12][10010],c[110];
long long gg[1010][1010],bc[1010][1010];
bool f[10010];
struct edge
{
	long long u,v,w;
}g[10000010];
bool cmp(edge xx,edge yy)
{
	return xx.w<yy.w;
}
long long scs()
{
	long long scsum=0,tt=0,kk=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			g[++tt].u=i;
			g[tt].v=j;
			g[tt].w=gg[i][j];
		}
	}
	sort(g+1,g+tt+1,cmp);
	memset(f,0,sizeof(f));
	for(long long i=1;i<=tt;i++)
	{
		//	cout<<g[i].u<<' '<<g[i].v<<' '<<g[i].w<<endl;
		if((!f[g[i].u]||!f[g[i].v])&&g[i].w!=2139062143)
		{
			scsum+=g[i].w;
			kk++;
			f[g[i].u]=1;
			f[g[i].v]=1;
		}
		if(kk>=n-1)
		{
			break;
		}
	}
//	cout<<scsum<<endl;
	return scsum;
}
void dfs(long long x,long long summ)
{
	if(x>k)
	{
	//	cout<<summ<<' ';
		summ+=scs();
		minn=min(minn,summ);
		return;
	}
	if(c[x]==0)
	{
		dfs(x+1,summ);
	}
	else
	{
		dfs(x+1,summ);
			for(long long j=1;j<=n;j++)
			{
				for(long long jj=j+1;jj<=n;jj++)
				{
					bc[j][jj]=gg[j][jj];
					gg[j][jj]=gg[jj][j]=min(gg[j][jj],a[x][j]+a[x][jj]);
				}
			}
		dfs(x+1,summ+c[x]);
			for(long long j=1;j<=n;j++)
			{
				for(long long jj=j+1;jj<=n;jj++)
				{
					gg[j][jj]=gg[jj][j]=bc[j][jj];
				}
			}
	}
}
signed main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(gg,127,sizeof(gg));
	for(long long i=1;i<=m;i++)
	{
		long long u,v;
		long long w;
		cin>>u>>v>>w;
		gg[u][v]=gg[v][u]=w;
	}
	for(long long i=1;i<=k;i++)
	{
		long long sum=0;
		cin>>c[i];
		sum+=c[i];
		for(long long j=1;j<=n;j++)
		{
			cin>>a[i][j];
			sum+=a[i][j];
		}
		if(!sum)
		{
			cout<<0;
			return 0;
		}
		if(!c[i])
		{
			for(long long j=1;j<=n;j++)
			{
				for(long long jj=j+1;jj<=n;jj++)
				{
					gg[j][jj]=gg[jj][j]=min(gg[j][jj],a[i][j]+a[i][jj]);
				}
			}
		}
	}
	dfs(1,0);
	cout<<minn;
	return 0;
}
