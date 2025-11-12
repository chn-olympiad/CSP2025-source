#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=1e6+5;
struct edge{
	int u,v;
	int w;
	int f,id;
}e[maxm*2];
long long c[15];
int fa[maxn*2];
int idx,n,m,k;
int ys[maxm*2];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].f=1;
		e[i].id=i;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int t=m+(i-1)*n+j;
			e[t].u=j,e[t].v=n+i;
			cin>>e[t].w;
			e[t].f=0;
			e[t].id=t;
		}
	}
	sort(e+1,e+m+k*n+1,cmp);
	for(int i=1;i<=m+k*n;i++)
	{
		ys[e[i].id]=i;
	}
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<(1<<k);i++)
	{
		long long sum=0;
		int now=0;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				sum+=c[j+1],now++;
				for(int t=m+j*n+1;t<=m+j*n+n;t++)
				{
					e[ys[t]].f=1;
				}
			}
		}
		for(int j=1,res=n+now-1;j<=m+k*n&&res>0;j++)
		{
			if(!e[j].f) continue;
			int fx=find(e[j].u),fy=find(e[j].v);
			if(fx!=fy)
			{
				fa[fx]=fy;
				sum+=e[j].w;
				res--;
			}
		}
		for(int j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				for(int t=m+j*n+1;t<=m+j*n+n;t++)
				{
					e[ys[t]].f=0;
				}
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
