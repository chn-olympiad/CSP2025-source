#include<bits/stdc++.h>
using namespace std;
int n,m,k;

struct village
{
	int va;
	int ro[10010];
}vi[20];
struct road
{
	int u,v,w;
}a[2000010];

bool cmd(road x,road y)
{
	return x.w<y.w;
}

int fa[10010];
int get(int x)
{
	if(fa[x] == x)
	{
		return x;
	}
	else
	{
		return x = get(fa[x]);
	}
}
void merge(int x,int y)
{
	fa[x] = get(fa[y]);
}

bool vis[20];
void dfs(int now,bool vis[])
{
	if(now == n+1)
	{
		for(int i = 1;i<=k;i++)
		{
		}
		return;
	}
	vis[now] = 1;
	dfs(now+1,vis);
	vis[now] = 0;
	dfs(now+1,vis);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)
	{
		fa[i] = i;
	}
	for(int i = 1,u,v,w;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i = 1;i<=k;i++)
	{
		cin>>vi[i].va;
		for(int j = 1;j<=vi[i].va;j++)
		{
			cin>>vi[i].ro[j];
		}
	}
	sort(a+1,a+m+1,cmd);
	long long num1 = 0;
	for(int i = 1;i<=m;i++)
	{
		if(get(fa[a[i].u]) != get(fa[a[i].v]))
		{
			num1+=a[i].w;
			merge(fa[a[i].u],fa[a[i].v]);
		}
	}
	cout<<num1;
	if(1 == 2)
	{
		dfs(1,vis);
	}
	
	
	return 0;
}
