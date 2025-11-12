#include <bits/stdc++.h>
using namespace std;
const long long P=1e5+7,R=65536;
long long T,n,m,k,ans,sum,num,cnt,flag;
long long vis[100050],fa[100050];
vector<long long>vec[100050];

struct cy
{
	long long w[100050];
}c[11];
bool cmpc(const cy &a,const cy &b)
{
	return a.w[0]<b.w[0];
}

struct edge
{
	long long u,v,w;
}e[1100050];
bool cmpe(const edge &a,const edge &b)
{
	return a.w<b.w;
}

long long find(long long x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmpe);
	for(int i=1;i<=k;++i) for(int j=0;j<=n;++j) cin>>c[i].w[j];
	sort(c+1,c+k+1,cmpc);
	if(k==0)
	{
		for(int i=1;i<=m;++i)
		{
			long long xx=find(e[i].u),yy=find(e[i].v);
			if(xx!=yy)
			{
				fa[xx]=yy;
				sum+=e[i].w;
			}
		}
		cout<<sum;
	}
	else
	{
		ans=1e18;
		for(int j=1;j<=k;++j)
		{
			for(int b=1;b<=n;++b)
			{
				e[m+(j-1)*k+b].u=b;
				e[m+(j-1)*k+b].v=j+1*n;
				e[m+(j-1)*k+b].w=c[j].w[b];
			}
		}
		sort(e+1,e+m+k*n+1,cmpe);
		for(int i=1;i<=m+k*n;++i)
		{
			long long xx=find(e[i].u),yy=find(e[i].v);
			if(xx!=yy)
			{
				fa[xx]=yy;
				sum+=e[i].w;
			}
		}
		cout<<sum;
	}
	return 0;
}
