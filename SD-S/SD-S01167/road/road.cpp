#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10;
struct node
{
	int u,v,w;
}g[M];
int fa[N];
int n,m,k,ans;
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y)
{
	fa[find(x)]=find(y);
	return;
}
void kruskal()
{
	for(int i=1;i<=m;i++)
	{
		if(find(g[i].u)!=find(g[i].v))
		{
			ans+=g[i].w;
			join(g[i].u,g[i].v);
		}
	}
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
//	if(k==0)
//	{
		init();
		sort(g+1,g+1+m,cmp);
		kruskal();
		cout<<ans<<endl;
//	}
	return 0;
}
/*
5 6 0
1 2 1
1 3 1
2 4 6
3 4 5
3 5 3
4 5 2
*/
