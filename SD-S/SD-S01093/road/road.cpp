#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[12][10005],fa[10005],mi[10005][12];
struct node
{
	long long u,v,w;
}a[1000004];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
long long find(long long x)
{
	if(x==fa[x])
	{
		return fa[x];
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	for(long long i=1;i<=k;i++)
	{
		for(long long j=0;j<=n;j++)
		{
			scanf("%lld",&c[i][j]);
		}
		for(long long j=1;j<=n;j++)
		{
			mi[j][i]=c[i][j];
		}
	}
	
	long long ans=0,sum=1;
	for(long long i=1;i<=m;i++)
	{
		long long tx=find(a[i].u),ty=find(a[i].v);
		if(tx!=ty)
		{
			fa[tx]=ty;
			long long ret=a[i].w;
			for(long long j=1;j<=k;j++)
			{
				ret=min(ret,mi[tx][j]+mi[ty][j]);
				mi[ty][j]=min(mi[tx][j],mi[ty][j]);
			} 
			ans+=ret;
			sum++;
		}
		if(sum==n)
		{
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
