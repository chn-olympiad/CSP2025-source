#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+100;
const int M=1.5e7+100;
struct node
{
	int x,y,w;
}e[M];
int cnt;
int n,m,k;
void add(int x,int y,int w)
{
	e[++cnt].x=x;
	e[cnt].y=y;
	e[cnt].w=w;
	return ;
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int fa[N];
int find(int a)
{
	if (fa[a]==a) return a;
	return fa[a]=find(fa[a]);
}
void solve1()
{
	int ans=0;
	sort(e+1,e+1+cnt,cmp);
	for (int i=1;i<=cnt;i++)
	{
		int x=e[i].x;
		int y=e[i].y;
		int fx=find(x),fy=find(y);
		if (fx!=fy)
		{
			ans+=e[i].w;
			fa[fx]=fy;
		}
	}
	cout<<ans;
	return ;
}
int Min=0x3f3f3f3f;
void solve3()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++) add(i,j,Min);
	}
	solve1();
	return ;
}
int a[15][N];
int c[15];
void solve2()
{
	for (int i=1;i<=k;i++)
	{
		int c,w;
		cin>>c;
		for (int j=1;j<=n;j++) ;
	}
	return ;
}
signed main ()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) fa[i]=i;
	int flag=1;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	if (k==0) solve1(),exit(0);
	for (int i=1;i<=k;i++)
	{
		int w;
		cin>>c[i];
		Min=min(Min,c[i]);
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j]>0) flag=0;
		}
	}
	if (flag) solve3(),exit(0);
	if (n<=1e3+100) solve2(),exit(0);

	return 0;
}
