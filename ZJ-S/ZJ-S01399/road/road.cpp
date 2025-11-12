#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+20,M=1e6+10,K=15;
struct edge
{
	int u,v,w;
}e[4*M];
int f[N],n,m,pd[N][N],b[N][N],u,v,w,k,c[N],a[K][N],tot,sum,pdn;
int cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>pdn>>m>>k;
	n=pdn;
	memset(pd,0x3f,sizeof(pd));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		pd[u][v]=min(pd[u][v],w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	int MIN=~0ull/2;
	for(int o=0;o<(1<<k);o++)
	{
		n=pdn;
		tot=0;
		for(int i=1;i<=n+k;i++)
		{
			f[i]=i;
			for(int j=i+1;j<=n+k;j++)
			{
				b[i][j]=pd[i][j];
			}
		}
		int sum=0;
		for(int i=1;i<=k;i++)
		{
			if((1<<i-1)&o)
			{
				sum+=c[i];
				n++;
				for(int j=1;j<=pdn;j++)
				{
					b[j][n]=a[i][j];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(b[i][j]!=0x3f3f3f3f3f3f3f3f)
				{
					e[++tot]=edge{i,j,b[i][j]};
				}
			}
		}
		sort(e+1,e+tot+1,cmp);
		for(int i=1,cnt=0;i<=tot,cnt<n-1;i++)
		{
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy)continue;
			sum+=e[i].w;
			f[fx]=fy;
			cnt++;
		}
		MIN=min(MIN,sum);
	}
	cout<<MIN<<endl;
	return 0;
}

