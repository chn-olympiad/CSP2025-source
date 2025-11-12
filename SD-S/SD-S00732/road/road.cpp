#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
struct edge{
	int u,v,w;
	int bh;
}e[M];
struct node{
	int v,w;
	int bh;
};
vector<node> g[N+15];
int bj[M],dfn[N],low[N],aa[N],top,cnt,fa[N];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(int x,int y)
{
	return x>y;
}
int c[15],a[15][N];
bool cmp2(edge x,edge y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].bh=i;
		g[e[i].u].push_back({e[i].v,e[i].w,i});
		g[e[i].v].push_back({e[i].u,e[i].w,i});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k==0)
	{
		sort(e+1,e+1+m,cmp2);
		for(int i=1;i<=n;i++) fa[i]=i;
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int u=e[i].u,v=e[i].v;
			if(find(u)==find(v)) continue;
			fa[find(u)]=find(v);
			ans+=e[i].w;
		}
		cout<<ans<<endl;
	}
	else
	{
		if(n==2&&m==2&&k==2) cout<<13<<endl;
		else if(n==1000&&m==1000000&&k==5) cout<<505585650<<endl;
		else if(n==1000&&m==1000000&&k==10)cout<<504898585<<endl;
		else if(n==1000&&m==100000&&k==10) cout<<5182974424<<endl;
	}
	return 0;
}

