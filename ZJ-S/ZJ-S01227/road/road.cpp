#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10,M=2e6+10;
typedef pair<int,int> PII;
struct ed
{
	int u,v,w;
}edge[M];
int fa[N];
int n,m,k,num,ans;
int a[11][N];
int c[11];
int find(int x)
{
	if( fa[x] == x ) return x;
	return fa[x]=find(fa[x]); 
}
bool cmp(ed x,ed y)
{
	return x.w < y.w ;
}
int main()
{
	freopen("road.in","in",stdin); 
	freopen("road.out","out",stdout);
	scanf("%d%d%d",&n,&m,&k);
	printf("%d",n);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[++num]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",c+i);
		int x = 0 ;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if( a[i][j] == 0 ) x = j ;
		}
		for(int j=1;j<=n;j++)
		{
			if( x == j ) continue ;
			edge[++num]={x,j,a[i][j]};
		}
	}
	sort(edge+1,edge+1+num,cmp);
	for(int i=1;i<=num;i++)
	{

		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fu=find(u),fv=find(v);	
		if(fu==fv) continue ;
		fa[fu] = fv;
		ans += w ;
	}
	printf("%d",ans);
}