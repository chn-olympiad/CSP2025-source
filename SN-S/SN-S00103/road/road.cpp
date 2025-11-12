#include<bits/stdc++.h>
using namespace std;
int fa[10010];
int cha(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	fa[x]=cha(fa[x]);
	return fa[x];
}
struct node
{
	int u,v,w;
}a[1000010];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
long long ans=0;
int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1,u=0;;i++)
	{
		if(cha(a[i].u)!=cha(a[i].v)) 
		{
			fa[a[i].u]=cha(a[i].v);
			ans+=a[i].w;
			u++;
		}
		if(u==n-1)
			break;
	}
	if(k==0)
	{
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
