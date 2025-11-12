#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=1e3;
struct node
{
	ll u,v,w;
}e[MX*MX*4+10];
ll n,m,k,i,j,c[20],d[MX+10][MX+10],a[20][MX+10],fa[MX+10];
ll fnd(ll x)
{
	if(fa[x]==x)return x;
	return fa[x]=fnd(fa[x]);
}
bool cmp(node p,node q)
{
	return p.w<q.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(d,0x3f,sizeof(d));
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		d[u][v]=min(d[u][v],w);
	}
	bool f=1;
	m=0;
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]>0)f=0;
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		for(j=1;j<=n;j++)
		{
			for(int ii=j+1;ii<=n;ii++)
			{
				d[j][ii]=min(d[j][ii],a[i][j]+a[i][ii]);
			}
		}
	}
	if(f)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				e[++m].u=i;
				e[m].v=j;
				e[m].w=d[i][j];
			}
		}
	}
	if(f||k==0)
	{
		sort(e+1,e+1+m,cmp);
		ll sum=0;
		for(int i=1;i<=m;i++)
		{
			int xx=fnd(e[i].u);
			int yy=fnd(e[i].v);
			if(xx!=yy)
			{
				fa[yy]=xx;
				sum+=e[i].w;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
