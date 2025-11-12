// SN-S00090  华紫陌   西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node
{
	int u,v,w;
};
vector<node>g;
int c[11],w[10001][11];
int ans=0;
int fa[10001];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	x=fa[y];
}
bool check(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return 1;
	else return 0;
}
/*
void kruskal()
{
	for(int i=0;i<g.size();i++) fa[i]=i;
	sort(g.begin(),g.end(),cmp);
	for(int i=0;i<g.size();i++)
	{
		if(check(g[i].u,g[i].v)) continue;
		else
		{
			merge(g[i].u,g[i].v);
			ans+=g[i].w;
		}
	}
	
}
*/
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back((node){u,v,w});
		g.push_back((node){v,u,w});
	}
	/*
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>w[i][j];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int _=1;_<=k;_++)
			{
				g.push_back((node){i,j,w[_][i]+w[_][j]});
				g.push_back((node){j,i,w[_][i]+w[_][j]});
			}
	*/
//	kruskal();
	for(int i=0;i<g.size();i++) ans+=g[i].w;
	cout<<ans/2;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4

12
*/
