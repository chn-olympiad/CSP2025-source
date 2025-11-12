#include<bits/stdc++.h>
#define MX 3000000
using namespace std;
struct node
{
	int x;
	int y;
	int w;
}a[MX + 10];
struct node2
{
	int to;
	int w;
};
vector<node2> G[MX + 10];
int fa[MX + 10]; 
int dp[MX + 10],c[MX + 10];
long long f[MX + 10];
int n,m,k;
long long ans;
int fnd(int x)
{
	if (x == fa[x])
	{
		return x;
	}
	fa[x] = fnd(fa[x]);
	return fa[x];
}
void unite(int x,int y)
{
	fa[fnd(x)] = fnd(y);
}
bool cmp(node &x,node &y)
{
	return x.w < y.w;
}
bool cmp2(node &x,node &y)
{
	return x.w > y.w;
}
void dfs(int u,int fa)
{
	int i;
	for (i = 0;i < G[u].size();i++)
	{
		int v = G[u][i].to;
		if (v == fa)
		{
			continue;
		}
		if (!c[v] && c[u])
		{
			dp[u] = 1;
		}
		dfs(v,u);
		f[u] += (f[v] + G[u][i].w);
	}
	if (!dp[u])
	{
		ans -= f[u];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i,j;
	cin >> n >> m >> k;
	for (i = 1;i <= n + k;i++)
	{
		fa[i] = i;
	}
	for (i = 1;i <= m;i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].w;	
	}
	for (i = 1;i <= k;i++)
	{
		int d;
		cin >> d;
		for (j = 1;j <= n;j++)
		{
			int val;
			cin >> val;
			a[++m].x = n + i;
			a[m].y = j;
			a[m].w = val;	
			c[a[m].x] = 1;
		}
	}
	sort(a + 1,a + m + 1,cmp);
	for (i = 1;i <= m;i++)
	{
		int p = fnd(a[i].x),q = fnd(a[i].y);
		int u = a[i].x,v = a[i].y,val = a[i].w;
		G[u].push_back({v,val});
		G[v].push_back({u,val});
		if (p == q)
		{
			continue;
		}
		ans += a[i].w;
		unite(p,q);
	}
	dfs(1,0);
	cout << ans << endl;
	return 0;
}
/*
性质：原图的MST一定包含在城乡图的MST中 
*/
