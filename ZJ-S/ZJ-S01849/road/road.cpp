#include<bits/stdc++.h>
using namespace std;
const int N=2e4+7,M=2e6+7;
struct Edge
{
	int u,v,w;
}p[M];
int n,m,k,vlg[17][N],fa[N],edges;
inline int find(int f)
{
	return (fa[f]==f)?(f):(fa[f]=find(fa[f]));
}
inline void unity(int x,int y)
{
	fa[find(x)]=find(y);
	return;
}
inline bool same(int x,int y)
{
	return find(x)==find(y);
}
inline bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int kruskal()  //this is the classical code of the Kruskal's algorithm, how can we improve it so that we can finish the task?
{
	for(int i=0;i<=n+k+5;i++)
	{
		fa[i]=i;
	}
	int ans=0,cttn=0;
	sort(p+1,p+1+edges,cmp);
	for(int i=1;i<=edges;i++)
	{
		int u=p[i].u,v=p[i].v,w=p[i].w;
		if(!same(u,v))
		{
			unity(u,v);
			ans+=w;
			if(++cttn==n+k-1)
				break;
		}
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++) //a skill: village[0] is the cost for building.
		{
			scanf("%d",&vlg[i][j]);
			if(j>0)
				p[++edges]={n+i,j,vlg[i][j]};		
		}
	}
	printf("%d",kruskal());
	fclose(stdin);
	fclose(stdout);
	return 0;
}