#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,cnt,laste[10005],pre[10005],ans;
struct edge
{
	int u;
	int v;
	int w;
	int nxt;
}e[12000005];
void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=laste[u];
	laste[u]=cnt;
	return;
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int a)
{
	if(pre[a]==a) return a;
	else return pre[a]=find(pre[a]);
}
void join(int a,int b)
{
	pre[find(a)]=find(b);
	int aa=find(a);
	return;
}
void krus()
{
	int nw=0;
	for(int i=1;i<=n;i++) pre[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(pre[u]!=pre[v])
		{
			nw++;
			ans+=w;
			join(u,v);
		}
		if(nw==n-1) break;
	}
	cout<<ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	/*
	for(int i=1;i<=k;i++)
	{
		int v[10005];
		for(int j=1;j<=n;j++) cin>>v[i];
		for(int j=1;j<=n;j++)
		{
			for(int t=1;t<=n;t++)
		}
	}*/
	if(!k)
	{
		sort(e+1,e+cnt+1,cmp);
		krus();
		return 0;
	}
	return 0;
}
/*
5 6 0
2 5 4
1 5 5
4 1 6
3 4 5
5 3 3
3 2 2

6 8 0
1 4 5
1 3 8
1 6 6
3 6 7
6 4 4
4 5 2
4 2 5
5 2 3
*/
