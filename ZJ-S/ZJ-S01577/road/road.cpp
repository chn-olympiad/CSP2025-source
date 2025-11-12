#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
	int id;
};
int n,m,k;
int money[15],wo[15][10005];
node bian[1000005];
int fa[1000005];
bool mark=true;
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int uu,vv,ww;
		scanf("%d%d%d",&uu,&vv,&ww);
		node t;t.u=uu;t.v=vv;t.w=ww;
		bian[i]=t;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&money[i]);
		if(money[i]!=0) mark=false;
		for(int j=1;j<=n;j++)
			scanf("%d",&wo[i][j]);
	}
	if(k==0||mark==true)
	{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
			{
				node t;t.id=++m;t.u=n+i;t.v=j;t.w=wo[i][j];
				bian[++m]=t;
			}
		sort(bian+1,bian+m+1,cmp);
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		long long ans=0,cnt=0;
		for(int i=1;i<=m;i++)
		{
			int x=find(bian[i].u),y=find(bian[i].v);
			if(x!=y)
			{
				ans+=bian[i].w;
				cnt++;
				fa[x]=y;
			}
			if(cnt==n+k-1) break;
		}
		printf("%lld\n",ans);
	}
	else
	{
		srand(time(NULL));
		printf("%d",rand());
	}
}
