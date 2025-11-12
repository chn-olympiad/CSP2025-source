//臧家乐  SN-S00605  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e8+5;
int k;
int n,m;
struct node
{
	int u;
	int v;
	int w;
}e[M];

int fa[N];
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int ans,cnt;
int f[15];
void ch()
{
	for(int i=1;i<=m+n*k;i++)
	{
		if(cnt==n-1)
			return;
		int xx=find(e[i].u);
		int yy=find(e[i].v);
		int ww=e[i].w;
		if(xx==yy)
			continue;
		ans+=ww;
		cnt++;
		fa[xx]=yy;
	}
}
int a[15][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	int op=0;
	for(int i=1;i<=k;i++)
	{
		cin>>f[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				op++,e[op+m].u=j,e[op+m].v=k,e[op+m].w=a[i][j]+a[i][k];
	}
	sort(e+1,e+m+op+1,cmp);
	ch();
	cout<<ans;
	return 0;
}
