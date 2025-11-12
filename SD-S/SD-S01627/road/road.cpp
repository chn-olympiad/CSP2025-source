#include<cstdio>
#include<algorithm>
#include<vector>
#define man 1000005
struct node
{
	int u,v,w;
	bool operator <(const node b)const
	{
		return w<b.w;
	}
}e[man];
int fa[man];
int n,m,k;
long long ans;
int findd(int x)
{
	if(fa[x]==x) return fa[x];
	fa[x]=findd(fa[x]);
	return fa[x];
}
int mergee(int a,int b)
{
	int x=findd(a),y=findd(b);
	if(x!=y) fa[x]=y;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i]=(node){u,v,w};
	}
	int cntt=m;
	for(int i=1;i<=k;i++)
	{
		int t;
		scanf("%d",&t);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&t);
			e[++cntt]=(node){j,n+i,t};
		}
	}
	std::sort(e+1,e+cntt+1);
	int cnt=0;
	for(int i=1;i<=m+k;i++)
	{
		
		int x=e[i].u,y=e[i].v;
		printf("%d %d %d\n",x,y,e[i].w);
		if(findd(x)!=findd(y))
		{
			mergee(x,y);
			ans+=e[i].w;
			if(y<=n) cnt++;//只连已有 
		}
		if(cnt==n-1) break;
	}
	printf("%lld\n",ans);
	return 0;
}
