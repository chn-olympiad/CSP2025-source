#include<bits/stdc++.h>
using namespace std;
int fa[20010],siz[20010];
int u[1000010],v[1000010],w[1000010];
int c[11],a[11][10010];
int mp[1010][1010];
int find(int x)
{
	return(x==fa[x]?x:fa[x]=find(fa[x]));
}
void merge(int x,int y)
{
	int a=find(x),b=find(y);
	if(siz[a]>siz[b])
	{
		swap(a,b);
	}
	if(a!=b)
	{
		fa[a]=b;
	}
}
struct edge
{
	int u,v,w;
	bool operator<(const edge&b)const
	{
		return w<b.w;
	}
}e[2000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	int flag=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		int flag1=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			{
				flag1=1;
			}
		}
		if(c[i]!=0||flag1==0)
		{
			flag=0;
		}
	}
	long long ans=LLONG_MAX;
	for(int i=(flag==1?((1<<k)-1):0);i<(1<<k);i++)
	{
		long long sum=0;
		int tot=0;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				sum+=c[j];
				for(int l=1;l<=n;l++)
				{
					e[++tot]=(edge){l,j+n,a[j][l]};
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			e[++tot]=(edge){u[j],v[j],w[j]};
		}
		sort(e+1,e+1+tot);
		for(int j=1;j<=n+k;j++)
		{
			fa[j]=j;
			siz[j]=1;
		}
		for(int j=1;j<=tot;j++)
		{
			int u=e[j].u,v=e[j].v,w=e[j].w;
			if(find(u)!=find(v))
			{
				merge(u,v);
				sum+=w;
			}
		}
//		if(sum==0)
//		{
//			printf("i=%d sum=0\ne:",i);
//			for(int i=1;i<=tot;i++)
//			{
//				printf("(%d,%d,%d)\n",e[i].u,e[i].v,e[i].w);
//			}
//		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
