#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w,nxt;
} a[1001000];
int head[1001000];
int cnt = 0;
void addedge(int u, int v,int w)
{
	a[++cnt].v = v;
	a[cnt].u = u;
	a[cnt].w = w;
	a[cnt].nxt = head[u];
	head[u] = cnt;
}
int c[1001000];
int g[20][1001000];
bool vis[20];
int f[11000];
int findfa(int v)
{
	if(f[v] == v) return v;
	else return f[v] == findfa(f[v]);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	memset(g,127,sizeof(g));
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>g[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	memset(vis,0,sizeof(vis));
	long long ans = 0;
	int cnt1 = 0;
	for(int i=1;i<=n;i++)
	{
		f[i] = i;
	}
	for(int i=1;i<=m;i++)
	{
		int x1 = findfa(a[i].u);
		int x2 = findfa(a[i].v);
		int u = a[i].u;
		int v = a[i].v;
		int w = a[i].w;
		if(x1!=x2)
		{
			cnt1++;
			int pre = w;
			ans+=pre;
			f[x1] = x2;	
			if(cnt1 == n)
			{
				cout<<ans<<endl;
				return 0;
			}
		}
	} 
	return 0;
}